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
	param_name = utils.add_my(utils.replace_brackets(name))

	if header:
		end = ";"
	else:
		end = " {"

	if (sig["type_of_type"] == "builtin"):
		return "" 

	if sig["type_of_type"] == "array":
		num_arrys = (utils.strip_num_elements(sig["member_type"]))
		mem_type = utils.strip_type(utils.remove_prepend(sig["member_type"]))

		decl = "string" + " " + utils.add_serialize(utils.replace_brackets(name)[:-1]) + '('

		decl += mem_type + " " + param_name[:-1] + "[" + str(sig["element_count"]) + "]" 

		for a in num_arrys:
			decl += "["+ a + "]"
		decl += ') ' + end + '\n'
		##"*" * num_arrys) + " " + param_name[:-1] + '[' + str(sig["element_count"]) + '])' + end + '\n' 
	
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
	member_type = utils.add_serialize(utils.replace_brackets(sig["member_type"]))
	
	if utils.has_prepend(sig["member_type"]):
		member_type = member_type[:-1]

	num_values = sig["element_count"]

	if utils.has_prepend(name) == True:
		pname = utils.add_my(utils.replace_brackets(name)[:-1])
	else:
		pname = utils.add_my(name)

	body = """    vector<string> param_pairs; \n \n    // value to string conversion \n    string type = "{name}"; \n    vector <string> elements; \n \n"""
	mbody = body.format(name=utils.remove_prepend(name))

	mem_string = """    for (int i = 0; i < {iterations}; i++) {{ \n         elements.push_back({mtype_handle}({pname}[i]));\n    }}\n    stringstream value;\n    value << serialize_array(elements); \n"""
	mem_format = mem_string.format(iterations=str(num_values), pname=pname, mtype_handle=member_type)			
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

		if utils.has_prepend(mem["type"]) == True:
			mtype_handle = utils.add_serialize(utils.replace_brackets(mtype)[:-1])
		else:
			mtype_handle = utils.add_serialize(mtype)

		mem_string = """    elements.push_back(serialize_pair("{mname}", {mtype_handle}({my_name}.{mname2}), "object"));\n"""
		mem_format = mem_string.format(mname=name, mtype_handle=mtype_handle, my_name=utils.add_my(name), mname2=mname)		
		body += mem_format
	body+= " stringstream value;\n    value << serialize_object(elements); \n"

			
	body += """\n    // compose the inner description object\n    param_pairs.push_back(serialize_pair(TYPE_KEY, type, "string"));\n    param_pairs.push_back(serialize_pair(STRUCT_KEY, "true", "bool"));\n    param_pairs.push_back(serialize_pair(ARRAY_KEY, "false", "bool"));\n    param_pairs.push_back(serialize_pair(VALUE_KEY, value.str(), "object"));\n\n    return serialize_object(param_pairs);\n}}\n\n"""
	sbody = body.format(name=name)
	
	return sbody



