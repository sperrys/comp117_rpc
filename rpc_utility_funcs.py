#!/bin/env python

#
#  rpc_utility_funcs.py 
#  written by: Aaron Bowen, Spencer Perry
#
#  Purpose: Helpful functions written to add in
#  the generation of proxy and stub code for rpc 
#

import sys
import os
import basic_utils as utils 
import constants as c
import serializer 
import deserializer 
import proxy 
import stub


# ---------------------------------------------------------------- #
#							UTLITY FUNCTIONS 					   #
# ---------------------------------------------------------------- #


# Function that checks the validity of the command line 
# arguements provided by the user, returns filename if 
# correctly formmated 
# Returns: The filename provided

def CheckArgs(argv):
	try: 
		#  Proper Command Line Arguements
		if len(argv) != 2:
			raise "Wrong number of arguments"
		#  Check file permissions and Existance 
		filename = argv[1]

		if (not os.path.isfile(filename)):
			print >> sys.stderr, "Path %s does not designate a file" % filename
			raise "No file named " + filename
		if (not os.access(filename, os.R_OK)):
			print >> sys.stderr, "File %s is not readable" % filename
			raise "File " + filename + "not readable"

		return filename

	except Exception as e:
		print >> sys.stderr, "Usage: %s <idlfilename>" % sys.argv[0] 


# function that takes a filename and a type of generation (stub, or proxy)
# Returns: A String of the generated file comments and include statements
def generate_file_head(filename, stub_type):
	filebase = (os.path.splitext(filename)[0])
	include = "\n" * 3
	include += c.INCLUDE + utils.add_quotes(filename) + "\n"
	extension = "." + stub_type.lower() + ".cpp"

	if stub_type == "STUB":
		include = utils.gen_libs(include, "STUB")
	elif stub_type == "PROXY":
		include = utils.gen_libs(include, "PROXY")
	else: 
		raise "Improper stub type passed to generate_include()"

	comments = utils.gen_head_comments(filebase, extension, stub_type)
	namesspace = utils.gen_namespace(stub_type)
	constants = utils.gen_constants(stub_type)
	
	return comments + include + "\n" + namesspace + "\n" + constants + "\n" + "\n"

# Function that takes the idl types, 
# generates the corresponding 
# serialization header content and returns it
def generate_serial_header(idl_types):
	header_content = "//                  serilization.h\n//\n//     This is generated header file for the serialization \n\n\n"
	for name, sig in idl_types:
		header_content += serializer.construct_decl(name, sig, True)
	return header_content

# Function that takes the idl types, 
# generates the corresponding 
# serialization implementation content and returns it
def generate_serial_imp(idl_types):
	imp_content = ""
	for name, sig in idl_types:
		imp_content += serializer.construct_decl(name, sig, False) + serializer.construct_body(name, sig)
	return imp_content

# Function that takes the idl types, 
# generates the corresponding 
# serialization header content and returns it
def generate_deserial_header(idl_types):
	header_content = "//                  deserilization.h\n//\n//     This is generated header file for the serialization \n\n\n"
	for name, sig in idl_types:
		header_content += deserializer.construct_decl(name, sig, True)
	return header_content

# Function that takes the idl types, 
# generates the corresponding 
# deserialization implementation content and returns it
def generate_deserial_imp(idl_types):
	imp_content = ""
	for name, sig in idl_types:
		imp_content += deserializer.construct_decl(name, sig, False) + deserializer.construct_body(name, sig)
	return imp_content

# Function that takes the idl type and 
# generates the corresponding proxy functions
def generate_proxy_funcs(idl_funcs): 
	funcs = ""
	for name, sig in idl_funcs:
		f = ""
		f += proxy.construct_func_decl(name, sig)
		f += proxy.construct_func_body(name, sig)
		funcs += f 
	return funcs

# Function that takes the idl type and 
# generates the corresponding stub functions
def generate_stub_funcs(idl_funcs): 
	funcs = ""
	for name, sig in idl_funcs.iteritems():
		f = ""
		f += stub.construct_func_decl(name, sig)
		f += stub.construct_func_body(name, sig)
		funcs += f 

	funcs += stub.construct_dispatch_function(idl_funcs.iteritems())

	return funcs

# Function that generates the necessary files 
# for either the stub or the proxy, returns the functions
def generate_funcs(idl_funcs, stub_type):
	funcs = ""
	if stub_type == "PROXY":
		funcs += generate_proxy_funcs(idl_funcs);
	elif stub_type == "STUB":
		funcs += generate_stub_funcs(idl_funcs);
	return funcs 






# 
#		WRITTEN FUNCS, BUT NOT CURRENTLY USED
# 


# Function that takes the json and an array 
# parses the json and stores a string of the func sig
# in the provided array
# Returns: The array of string func sigs





# generated functions that aren't dependenet on idl
# Returns: string of generated code for basic functions
# 
# Todo: Proxy: add functions like jsonifyies and add_size_to_message
# 		Stub: add functions like get_json_size and get_json 
def generate_util_funcs(stub_type):
	basic_handle_funcs = ""

	for type_name in BASIC_TYPES:
		basic_handle_funcs += generate_handle(type_name, stub_type)

	return basic_handle_funcs

# generates functions that handle basic types
def generate_handle(type_name, stub_type):
	func = ""

	if stub_type == "STUB":
		func += generate_hand_func_decl(type_name, stub_type)
		func += generate_hand_func_body(type_name, stub_type)

	elif stub_type == "PROXY":
		func += generate_hand_func_decl(type_name, stub_type)
		func += generate_hand_func_body(type_name, stub_type)

	return func 
		

# function that generates the function declaration part of the handle functions
# ie. string handle_int(int my_int) {
# doesn't generate body of the function 
def generate_hand_func_decl(type_name, stub_type):
	decl = ""

	if stub_type == "PROXY": 
		decl = "string" + SPACE + add_handle(type_name) + "(" + type_name
		decl += SPACE + add_my(type_name) + ")" + SPACE + "{" + NEWLINE

	elif stub_type == "STUB":
		return ""

	return decl 

# STILL NEED TO FINISH FOR STUB
# function that generates the function body for handle functions
# might add a general create_func that takes an array of function lines
# and adds apropriate indents and newlines
def generate_hand_func_body(type_name, stub_type):
	body = ""
	if stub_type == "PROXY": 
		body += SPACE * INDENT + "vector<string>param_pairs" + SEMICOLON + NEWLINE + NEWLINE
		body += SPACE * INDENT + COMMENT + "value to string conversion" + NEWLINE
		body += SPACE * INDENT + "string type = " + add_quotes(type_name) + SEMICOLON + NEWLINE
		body += SPACE * INDENT + "stringstream value" + SEMICOLON + NEWLINE
		body += SPACE * INDENT + "value << " + add_my(type_name) + NEWLINE + NEWLINE
		body += SPACE * INDENT + COMMENT + "compose the inner description object" + NEWLINE

		return body + NEWLINE + "}" + NEWLINE

	elif stub_type == "STUB":
		return ""


