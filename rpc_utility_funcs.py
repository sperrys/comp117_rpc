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

# ---------------------------------------------------------------- #
#					  UTLITY CONSTANTS & ARRAYS				       #
# ---------------------------------------------------------------- #

# Constants for formatting  
CENTERED = 20
OFFSET = 10
INDENT = 4

# Constants for templating
COMMENT = "//"
SEMICOLON = ";"
COMMA = ','
NEWLINE = "\n"
SPACE = " "
EQUALS = "="
CONSTANT = "const "

INCLUDE = "#include "
NAMESPACE = "using namespace "

# These arrays define the libaries included 
# for the stub 
STUB_GLOBALS = ["string", "cstdio", "cstring", "utility.h"]
STUB_LOCALS = ["rpcstubhelper.h", "c150debug.h"]

# These arrays define the libaries included 
# for the proxy
PROXY_GLOBALS  = ["vector", "cstring", "cstdio", "stdbool.h", "iostream", "sstream"]
PROXY_LOCALS = ["rpcproxyhelper.h", "c150debug.h", "utility.h"]

#These arrays define the namespaces for each file 
P_NAMESPACE = ["C150NETWORK", "std"]
S_NAMESPACE = ["C150NETWORK"] 

#These arrays define the constants for each file
P_CONSTANTS = ["string VALUE_KEY = \"value\"", "string TYPE_KEY = \"type\"",
			   "string STRUCT_KEY = \"is_struct\"", "string ARRAY_KEY = \"is_array\""]

S_CONSTANTS = []

# Array of Basic Types Supported
BASIC_TYPES = ["int", "bool", "string", "char", "float", "void"]


# ---------------------------------------------------------------- #
#							UTLITY FUNCTIONS 					   #
# ---------------------------------------------------------------- #


# function that adds quotes to word ie word -> "word"
# Returns: the quoted version of the word
def add_quotes(word):
	return "\""+word+"\""

# function that adds arrows to word ie word -> <word>
# Returns: the arrowed version of the word 
def add_arrows(word):
	return "<"+word+">"


# function that generates the constants for a given stub type 
# Returns: the string of all the constants
def gen_constants(stub_type): 
	constants = ""
	
	if stub_type == "STUB":
		for n in S_CONSTANTS:
			constants += CONSTANT + n + SEMICOLON + NEWLINE

	elif stub_type == "PROXY":
		for n in P_CONSTANTS:
			constants +=  CONSTANT + n + SEMICOLON + NEWLINE
			
	return constants

# function that takes a stub_type and generates namespace
# Returns: the string of the namespace 
def gen_namespace(stub_type):
	n_spaces = ""
	
	if stub_type == "STUB":
		for n in S_NAMESPACE: 
			n_spaces += NAMESPACE + n + SEMICOLON + NEWLINE

	elif stub_type == "PROXY":
		for n in P_NAMESPACE: 
			n_spaces += NAMESPACE + n + SEMICOLON + NEWLINE

	return n_spaces

# function takes the current include statement
# and the stub type, then loops through the 
# global libraries and local libarys for the 
# particular stub type
# Returns: An updated string with the correct library includes

def gen_libs(include, stub_type):

	if stub_type == "STUB":
		for g_lib in STUB_GLOBALS: 
			include += INCLUDE + add_arrows(g_lib) + NEWLINE
		for l_lib in STUB_LOCALS:
			include += INCLUDE + add_arrows(l_lib) + NEWLINE

	elif stub_type == "PROXY":
		for g_lib in PROXY_GLOBALS: 
			include += INCLUDE + add_arrows(g_lib) + NEWLINE
		for l_lib in PROXY_LOCALS:
			include += INCLUDE + add_arrows(l_lib) + NEWLINE

	return include

# function that takes the filebase and the file extension
# and generates comments for the head of the file
# Returns: string of the file comments  
def gen_head_comments(filebase, extension, stub_type):
	comments =  COMMENT + " --------------------------------------------------------------" + NEWLINE  
	comments += (COMMENT + NEWLINE) * 2
	comments += COMMENT + SPACE * CENTERED + filebase + extension + SPACE* CENTERED + NEWLINE 
	comments += COMMENT + NEWLINE
	comments += COMMENT + SPACE * OFFSET + "Authors: Aaron Bowen, Spencer Perry" + NEWLINE
	comments += COMMENT + SPACE * OFFSET + "This is an auto-generated " + stub_type.lower() + "." +  NEWLINE
	comments += (COMMENT + NEWLINE) * 2
	comments +=  COMMENT + " --------------------------------------------------------------" + NEWLINE

	return comments

# function that takes a filename and a type of generation (stub, or proxy)
# Returns: A String of the generated file comments and include statements
def generate_file_head(filename, stub_type):

	filebase = (os.path.splitext(filename)[0])

	include = NEWLINE * 3
	include += INCLUDE + add_quotes(filename) + NEWLINE

	if stub_type == "STUB":

		extension = ".stub.cpp"
		include = gen_libs(include, "STUB")

	elif stub_type == "PROXY":

		extension = ".proxy.cpp"
		include = gen_libs(include, "PROXY")

	else: 
		raise "Improper stub type passed to generate_include()"

	comments = gen_head_comments(filebase, extension, stub_type)
	namesspace = gen_namespace(stub_type)
	constants = gen_constants(stub_type)
	
	return comments + include + NEWLINE + namesspace + NEWLINE + constants + NEWLINE + NEWLINE


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


# function that prepends the word handle to a word
# Returns: prepended word 
def add_handle(name):
	return "handle_"+ name

# function that prepends my in front of name 
# Returns: prepended word
def add_my(name):
	return "my_"+ name

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


def construct_idl_type_decl(name, sig):

	if (sig["type_of_type"] == "builtin"):
		return "" 

	decl = "string" + SPACE + add_handle(name) + '(' 

	if sig["type_of_type"] == "array":
		decl += sig["member_type"] + SPACE + add_my(name) + SPACE + '[' + str(sig["element_count"]) + ']' + SPACE +  ')' + '{' + NEWLINE

	# if the type is an array, create function decl that takes in the struct 
	if sig["type_of_type"] == "struct":
		decl += name + SPACE + add_my(name) + ')' + SPACE + '{' + NEWLINE 

	return decl 


def construct_idl_type_body(name, sig):
	body = ""

	if sig["type_of_type"] == "struct":
		body += handle_p_type_struct(name, sig)
	if sig["type_of_type"] == "array":
		body += handle_p_type_array(name, sig)
	
	return body 


# Code that generates the handling of a proxy array type
def handle_p_type_array(name, sig):
	member_type = add_handle(sig["member_type"])
	num_values = sig["element_count"]
	mname = add_my(name)

	body = """    vector<string> param_pairs; \n \n    // value to string conversion \n    string type = "{name}"; \n    vector <string> elements; \n \n"""
	mbody = body.format(name=name)
	
	mem_string = """    for (int i = 0; i < {iterations}; i++) {{ \n         elements.push_back({mtype_handle}({mname}[i]));\n    }}\n    stringstream value;\n    value << jsonify_array(elements); \n"""
	mem_format = mem_string.format(iterations=str(num_values-1), mname=mname, mtype_handle=member_type, mname2=mname)
			
	mbody += mem_format
			
	
	mbody += """\n    // compose the inner description object\n    param_pairs.push_back(jsonify_pair(TYPE_KEY, type, "string"));\n    param_pairs.push_back(jsonify_pair(STRUCT_KEY, "false", "bool"));\n    param_pairs.push_back(jsonify_pair(ARRAY_KEY, "true", "bool"));\n    param_pairs.push_back(jsonify_pair(VALUE_KEY, value.str(), "object"));\n\n    return jsonify_object(param_pairs);\n}\n\n"""
	
	return mbody


# Code that generates the handling of a proxy struct type
def handle_p_type_struct(name, sig):
	body = """    vector<string> param_pairs; \n \n    // value to string conversion \n    string type = "{name}"; \n    vector <string> elements; \n \n"""
	sbody = ""
	# loop through eahc member of the struct
	for mem in sig["members"]:
		mname = mem["name"]
		mtype = mem["type"]
		mtype_handle = add_my(mtype)

		mem_string = """    elements.push_back(jsonify_pair("{mname}", {mtype_handle}({my_name}.{mname2}), "object");\n"""
		mem_format = mem_string.format(mname=mname, mtype_handle=mtype_handle, my_name=name, mname2=mname)
			
		body += mem_format
			
	
	body += """\n    // compose the inner description object\n    param_pairs.push_back(jsonify_pair(TYPE_KEY, type, "string"));\n    param_pairs.push_back(jsonify_pair(STRUCT_KEY, "true", "bool"));\n    param_pairs.push_back(jsonify_pair(ARRAY_KEY, "false", "bool"));\n    param_pairs.push_back(jsonify_pair(VALUE_KEY, value.str(), "object"));\n\n    return jsonify_object(param_pairs);\n}}\n\n"""
  	sbody = body.format(name=name)
	
	return sbody


def proxy_type_funcs(idl_types): 
	idl_type_funcs = ""

	for name, sig in idl_types:
			func = ""
			func = construct_idl_type_decl(name, sig)
			func += construct_idl_type_body(name, sig)
			idl_type_funcs += func 

	return idl_type_funcs

# functions associated with idl types, dependent on idl 
def generate_idl_type_func(idl_types, stub_type):

	idl_type_funcs = ""
	if stub_type == "PROXY":
		idl_type_funcs += proxy_type_funcs(idl_types);

	elif stub_type == "STUB":
		idl_type_funcs += stub_type_funcs(idl_types);
	return idl_type_funcs



def construct_idl_func_decl(name, sig):

	# Python Array of all args (each is a hash with keys "name" and "type")
	args = sig["arguments"]
	# Make a string of form:  "type1 arg1, type2 arg2" for use in function sig
	argstring = ', '.join([a["type"] + ' ' + a["name"] for a in args])
	# Construct Variable of function name signature)
	func_sig = sig["return_type"] + " " + name +'(' + argstring +')'
	# Add signature to list 
	return (func_sig + "  " + '{'  + NEWLINE)

def construct_idl_func_body(name, sig):
	args = sig["arguments"]
	num_args = len(args)
	body = """    // Compose the remote call\n string message; \n    vector<string> pairs; \n"""
	body += """    //Remote Call metadata \n    pairs.push_back(jsonify_pair("method", "{name}", "string"));\n"""
 	body += """    pairs.push_back(jsonify_pair("param_count", "{param_count}, "string)); \n \n"""
 	body += """   // Remote call params \n    vector<string> param_objects; \n """

 	b = body.format(param_count=num_args, name=name)
 	body = b 

 	for a in args: 
 		m = """   param_objects.push_back({type}, {name}));\n  """;
 		f_m = m.format(type=add_handle(a["type"]), name=a["name"])
 		body += f_m

 	body += """    string params = jsonify_array(param_objects); \n """
  	body += """    pairs.push_back(jsonify_pair("params", params, "array")); \n""" 
	body += """    // Finalize the message \n  """ 
  	body += """    message = jsonify_object(pairs);\n"""

  	body += """    // Send the remote call\n"""
  	body += """   c150debug->printf(C150RPCDEBUG," {name}() invoked");\n"""
 	body += """   RPCPROXYSOCKET->write(message.c_str(), message.length() + 1); // write function name including null \n""" 

  	body += """   // Read the response\n """
  	body += """   char readBuffer[5];  // to read magic value DONE + null \n"""
  	body += """   c150debug->printf(C150RPCDEBUG,"{name}() invocation sent, waiting for response");\n"""
  	body += """RPCPROXYSOCKET->read(readBuffer, sizeof(readBuffer)); // only legal response is DONE \n }} """

  	f_body = body.format(name=name)

	return body

def proxy_func_funcs(idl_funcs): 
	funcs = ""

	for name, sig in idl_funcs:
		func = ""
		func += construct_idl_func_decl(name, sig)
		funcs += construct_idl_func_body(name, sig)
		print func 

	return funcs
	
def stub_func_funcs(idl_funcs): 
	return ""


# functions associated with idl funcs, dependent on idl 
def generate_idl_func_func(idl_funcs, stub_type):
	idl_func_funcs = ""
	if stub_type == "PROXY":
		idl_func_funcs += proxy_func_funcs(idl_funcs);

	elif stub_type == "STUB":
		idl_func_funcs += stub_func_funcs(idl_funcs);
	return idl_func_funcs










#
#	 				TODO: FUNCS 
# 

# Need ot check this 
def write_func_decl(return_type, name, params): 
	decl = return_type + SPACE + name +'('

	for i in params:
		decl + params[i].type + SPACE + params[i].name

		if i != length(params):
			decl += COMMA + SPACE

	decl += ')'
	return decl




def stub_type_funcs(idl_types):
	idl_type_funcs = ""

	return idl_type_funcs












# 
#		WRITTEN FUNCS, BUT NOT CURRENTLY USED
# 


# Function that takes the json and an array 
# parses the json and stores a string of the func sig
# in the provided array
# Returns: The array of string func sigs


	return function_array



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
		



