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
	decl = ""
	if header:
		end = ";"
	else:
		end = " {"
	if (sig["type_of_type"] == "builtin"):
		return "" 
	if sig["type_of_type"] == "array":	 	
		decl += utils.strip_type(utils.remove_prepend(sig["member_type"])) + " *" + "*" * (len(utils.strip_num_elements(sig["member_type"])))
		decl += utils.add_deserialize(utils.replace_brackets(name)[:-1]) + "(string json)" + end + "\n"
	elif sig["type_of_type"] == "struct":
		decl += name + " "
		decl += utils.add_deserialize(utils.replace_brackets(name)) + "(string json)" + end + "\n"

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

# Function that handles the serialization of a Struct Type
def handle_struct(name, sig):
	body = "\n    " + name + " *"+ utils.add_my(name) + " = new struct " + name + ";\n"
	body += "    string value_obj = extract_object(json, \"value\");\n\n"

	# loop through each member of the struct
	for mem in sig["members"]:
		f = ""
		mname = mem["name"]
		mtype = mem["type"]

		# if the struct member is not an array
		if  ((utils.has_prepend(mtype)) == False):
			mtype_handle = utils.add_deserialize(mtype)
			mem_string = "    "+utils.add_my(name)+"->{mname} = {mtype_handle}(extract_object(value_obj, \"{mname}\"));\n" 
			mem_format = mem_string.format(mname=mname, mtype_handle=mtype_handle)		
			body += mem_format
		# if the struct member is an array
		else:
			mtype_handle = utils.add_deserialize(utils.replace_brackets(mtype)[:-1])
			mem_string = "    " + utils.strip_type(utils.remove_prepend(mtype)) + " *" + mname + " = "
			mem_string +=" {mtype_handle}(extract_object(value_obj, \"{mname}\")); \n" 
			mem_string +="    for (int i = 0; i < {num_elements}; i++) {{ {my_name}->{mname}[i] = {mname}[i]; }}\n\n"
			f = mem_string.format(mtype_handle=mtype_handle, mname=mname, my_name=utils.add_my(name), num_elements=utils.strip_num_elements(mtype)[0])
			body +=f 
	body += "\n    return *" +utils.add_my(name)+ "\n}\n \n"
	
	return body 

# function that handles array 
def handle_array(name, sig):
	height = len(utils.strip_num_elements(sig["member_type"]))
	num_values = sig["element_count"]
	mtype = sig["member_type"]

	if utils.has_prepend(mtype):
		mtype_h = utils.add_deserialize(utils.replace_brackets(sig["member_type"])[:-1])
	else: 
		mtype_h = utils.add_deserialize(utils.replace_brackets(sig["member_type"]))

	mname = utils.add_my(utils.strip_type(mtype))

	mbody =  "    {array_type} {height} {mname}[{num_elements}] = new {pname}{height}[{num_elements}];\n"
	mbody += "    string objs = extract_array(json, \"value\");\n\n"

	mbody += "    for (int i = 0; i < {num_elements}; i++) {{\n"
	mbody += "         {mname}[i] = "+mtype_h+"(consume_object(objs));\n" 
	mbody += "    }}\n\n"
	mbody += "    return {mname}; \n}} \n" 


	f = mbody.format(mname=mname, array_type=utils.strip_type(utils.remove_prepend(mtype)), pname=utils.strip_type(utils.remove_prepend(name)), num_elements=num_values, height=height * "*")
	
	return f 

