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

# Constants for templating
COMMENT = "//"
SEMICOLON = ";"
NEWLINE = "\n"
SPACE = " "
EQUALS = "="
CONSTANT = "const "

INCLUDE = "#include "
NAMESPACE = "using namespace "

# These arrays define the libaries included 
# for the stub 
STUB_GLOBALS = ["string", "cstdio", "cstring"]
STUB_LOCALS = ["rpcstubhelper.h", "c150debug.h"]

# These arrays define the libaries included 
# for the proxy
PROXY_GLOBALS  = ["vector", "cstring", "cstdio", "stdbool.h", "iostream", "sstream"]
PROXY_LOCALS = ["rpcproxyhelper.h", "c150debug.h"]

#These arrays define the namespaces for each file 
P_NAMESPACE = ["C150NETWORK", "std"]
S_NAMESPACE = ["C150NETWORK"] 

#These arrays define the constants for each file
P_CONSTANTS = ["string VALUE_KEY = \"value\"", "string TYPE_KEY = \"type\"",
			   "string STRUCT_KEY = \"is_struct\"", "string ARRAY_KEY = \"is_array\""]

S_CONSTANTS = []


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
	
	return comments + include + NEWLINE + namesspace + NEWLINE + constants


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
		print(e)
		print >> sys.stderr, "Usage: %s <idlfilename>" % sys.argv[0] 

# Function that takes the json and an array 
# parses the json and stores a string of the func sig
# in the provided array
# Returns: The array of string func sigs

def StoreFuncSigStrings(json, function_array):
	# Loop storing each function signature in json as string
	for  name, sig in json["functions"].iteritems():
		# Python Array of all args (each is a hash with keys "name" and "type")
		args = sig["arguments"]
		# Make a string of form:  "type1 arg1, type2 arg2" for use in function sig
		argstring = ', '.join([a["type"] + ' ' + a["name"] for a in args])
		# Construct Variable of function name signature)
		func_sig = sig["return_type"] + " " + name +'(' + argstring +')'
		# Add signature to list 
		function_array.append(func_sig)

	return function_array


# functions associated with idl types, dependent on idl 
def generate_idl_type_func(idl_types, stub_type):
	return ""


# functions associated with idl funcs, dependent on idl 
def generate_idl_func_func(idl_funcs, stub_type):
	return ""


# generated functions that aren't dependenet on idl 
def generate_util_funcs(stub_type):
	return ""








