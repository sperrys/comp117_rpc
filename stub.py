#!/bin/env python

#
#  proxy.py 
#  written by: Aaron Bowen, Spencer Perry
#
#  Purpose: functions specific to the proxy 
# 

import basic_utils as utils 
import constants as c


# This function constructs the stub function decl
# for a given function name and signature 
def construct_func_decl(name, sig):
	decl = "void " + utils.add_prepend(name) + "(string json, int param_count, string params) { \n"
	return decl 

# This function constructs the stub function body
# for a given function name and signature 
def construct_func_body(name, sig):
	body = "\n"
	args = sig["arguments"]
	rtype = sig["return_type"] + " result = "
	is_result = "result"

	if sig["return_type"] == "void":
		rtype = ""
		is_result =""

	for a in args: 
		pname = a["name"]

		if utils.has_prepend(a["type"]) == True:
			num_arrys = 1
			ptype = utils.strip_type(utils.remove_prepend(a["type"]))
			ptypehandle = utils.add_deserialize(utils.replace_brackets((a["type"]))[:-1])
			num_arrys = len(utils.strip_num_elements(a["type"]))

		else:
		 	ptype = a["type"]
		 	num_arrys = 0
		 	ptypehandle = utils.add_deserialize(utils.replace_brackets((a["type"])))
	
		param = "      {ptype} {num_arrys}{pname} = {ptypehandle}(consume_object(params));\n"
		f_param = param.format(ptype=ptype, num_arrys=num_arrys * "*", ptypehandle=ptypehandle, pname=pname)
		body += f_param

	body += "\n      // Time to Call The Function\n \n"
	body += "      c150debug->printf(C150RPCDEBUG,\"stub - invoking {name}() \");\n"
	body += "      " + rtype +" {name}("
	
	for a in args:
		body += a["name"]
		if a != args[-1]:
			body += ", "
	body += "); \n\n"

	body+= "      // Compose the remote call\n"
  	body+= "      vector<string> pairs;\n"
  	body+= """      pairs.push_back(serialize_pair("method", "{name}", "string"));\n"""
  	body+= """      pairs.push_back(serialize_pair("error", "false", "bool"));\n"""
  	body+= """      pairs.push_back(serialize_pair("result", {rtypehandle}({is_result}), "object"));\n"""
  	body+= """      string message = serialize_object(pairs);\n\n """

  	body += """     // Send the response to the client\n""" 
  	body += """      c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");\n"""
  	body += """      RPCSTUBSOCKET->write(message.c_str(), message.length() + 1);\n"""

	f = body.format(name=name, rtypehandle=utils.add_serialize(sig["return_type"]), is_result=is_result)
	return f + "}\n"

def construct_bad_function():
	decl = "void __badFunction(string func_name) { \n"
	body = "    char doneBuffer[5] = \"BAD\";  // to write magic value DONE + null  \n\n"
	body += "    // Send the response to the client indicating bad function\n"
	body += "    c150debug->printf(C150RPCDEBUG,\"simplefunction.stub.cpp: received call for nonexistent function %s()\", func_name);\n"
	body += "    RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);\n } \n"

	return decl + body 
# This function constructs the stub's dispatch function 
def construct_dispatch_function(idl_funcs):
	body ="" 
	decl = "\nvoid dispatchFunction() {\n"
	body += "    // Read the Json Message in \n"
	body += "    string json_str = read_message(RPCSTUBSOCKET, read_message_size(RPCSTUBSOCKET));\n\n"
	body += "    string func_name = extract_string(json_str, \"method\");\n"
	body += "    int param_count = extract_int(json_str, \"param_count\");\n"
	body += "    string params = extract_array(json_str, \"params\");\n\n"

	body += "    if(!RPCSTUBSOCKET->eof()) { \n"

	for name, sig in idl_funcs:
		body += "        if(func_name == \""+ name + "\")\n"
		body += "             "+ utils.add_prepend(name)+"(json_str, param_count, params); \n"

	body += "        else\n"
	body += "            __badFunction(func_name);\n"

	return decl + body + "    }\n}\n"
