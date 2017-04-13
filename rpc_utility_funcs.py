#!/bin/env python

#
#  rpc_utility_funcs.py 
#  written by: Aaron Bowen, Spencer Perry
#
#  Purpose: Helpful functions written to aid in
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
#														UTLITY FUNCTIONS	 					   				 #
# ---------------------------------------------------------------- #


# Function that checks the validity of the command line 
# arguements provided by the user, returns filename if 
# correctly formmated 
# Returns: The filename provided

def check_args(argv):
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
def generate_serial_header(idl_types, filename):
	header_content = "//                  serilization.h\n//\n//     This is generated header file for the serialization \n\n\n"
	#header_content += "#include \""+filename+"\"\n"
	for name, sig in idl_types:
		header_content += serializer.construct_decl(name, sig, True)
	return header_content

# Function that takes the idl types, 
# generates the corresponding 
# serialization implementation content and returns it
def generate_serial_imp(idl_types):
	imp_content = "//                  serilization.cpp\n//\n//     This is generated implementation file for the serialization \n\n\n#include \"generic_serialization.h\"\n#include \"gen.serialization.h\"\n\n\n"
	for name, sig in idl_types:
		imp_content += serializer.construct_decl(name, sig, False) + serializer.construct_body(name, sig)
	return imp_content

# Function that takes the idl types, 
# generates the corresponding 
# serialization header content and returns it
def generate_deserial_header(idl_types, filename):
	header_content = "//                  deserilization.h\n//\n//     This is generated header file for the serialization \n\n\n"
	#header_content += "#include \""+filename+"\"\n"
	for name, sig in idl_types:
		header_content += deserializer.construct_decl(name, sig, True)

	return header_content

# Function that takes the idl types, 
# generates the corresponding 
# deserialization implementation content and returns it
def generate_deserial_imp(idl_types):
	imp_content = "//                  deserilization.cpp\n//\n//     This is generated header file for the deserialization \n\n\n#include \"generic_deserialization.h\"\n#include \"gen.deserialization.h\"\n\n\n"
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
	funcs = "void dispatchFunction();\n\n"
	for name, sig in idl_funcs.iteritems():
		f = ""
		f += stub.construct_func_decl(name, sig)
		f += stub.construct_func_body(name, sig)
		funcs += f 

	funcs += stub.construct_bad_function()
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

