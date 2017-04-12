#!/bin/env python

#
#  serializer.py 
#  written by: Aaron Bowen, Spencer Perry
#
#  Purpose: Helpful functions written to aid
#  in the serialization process  
#

import basic_utils as utils 



# Function that takes in a type name, signature
# and whether the declaration is part of 
# the header or the implementation and returns it 
def construct_decl(name, sig, header):
	if header:
		end = ";"
	else:
		end = " {"

	if (sig["type_of_type"] == "builtin"):
		return "" 

	

	if sig["type_of_type"] == "array":
		decl = "string" + " " + utils.add_serialize(utils.replace_brackets(name)[:-1]) + '('
		decl += utils.remove_prepend(sig["member_type"]) + " " + utils.add_my(name) + " " + '[' + str(sig["element_count"]) + '])' + end + '\n' 	
	elif sig["type_of_type"] == "struct":
	    decl = "string" + " " + utils.add_serialize(name) + '('
	    decl += name + " " + utils.add_my(name) + ')' + end + "\n"

	return decl 

# Function that takes in a type name and signature
# Returns the body of the serialization function
def construct_body(name, sig):
	body = ""
	if sig["type_of_type"] == "struct":
		body += handle_struct(name, sig)
	if sig["type_of_type"] == "array":
		body += handle_array(name, sig)
	return body 

# Function that handles the serialization of an array type 
def handle_array(name, sig):
	member_type = utils.add_serialize(utils.replace_brackets(sig["member_type"])[:-1])
	num_values = sig["element_count"]
	mname = utils.add_my(name)

	body = """    vector<string> param_pairs; \n \n    // value to string conversion \n    string type = "{name}"; \n    vector <string> elements; \n \n"""
	mbody = body.format(name=utils.remove_prepend(name))

	mem_string = """    for (int i = 0; i < {iterations}; i++) {{ \n         elements.push_back({mtype_handle}({mname}[i]));\n    }}\n    stringstream value;\n    value << serialize_array(elements); \n"""
	mem_format = mem_string.format(iterations=str(num_values-1), mname=mname, mtype_handle=member_type, mname2=mname)			
	mbody += mem_format
	mbody += """\n    // compose the inner description object\n    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));\n    param_pairs.push_back(serialize_pair(STRUCT_KEY, "false", "bool"));\n    param_pairs.push_back(serialize_pair(ARRAY_KEY, "true", "bool"));\n    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));\n\n    return serialize_object(param_pairs);\n}\n\n"""
	
	return mbody

# Function that handles the serialization of a Struct Type
def handle_struct(name, sig):
	body = """    vector<string> param_pairs; \n \n    // value to string conversion \n    string type = "{name}"; \n    vector <string> elements; \n \n"""
	sbody = ""
	# loop through eahc member of the struct
	for mem in sig["members"]:
		mname = mem["name"]
		mtype = mem["type"]
		mtype_handle = utils.add_my(mtype)
		mem_string = """    elements.push_back(serialize_pair("{mname}", {mtype_handle}({my_name}.{mname2}), "object"));\n"""
		mem_format = mem_string.format(mname=mname, mtype_handle=utils.replace_brackets(mtype_handle)[:-1], my_name=name, mname2=mname)		
		body += mem_format
			
	body += """\n    // compose the inner description object\n    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));\n    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));\n    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));\n    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));\n\n    return serialize_object(param_pairs);\n}}\n\n"""
	sbody = body.format(name=name)
	
	return sbody