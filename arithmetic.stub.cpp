// --------------------------------------------------------------
//
//                        simplefunction.stub.cpp
//
//        Author: Noah Mendelsohn         
//   
//       This is a hand-crafted demonstration stub.
//
//       It implements a very simple protocol that works only
//       for functions with no arguments and void return. Invocation
//       requests are just the null terminated function name; 
//       Responses are the null terminated words DONE or BAD.
//       You'll have to do something much more sophisticated
//       for routines that accept and return values. (And you might
//       not want to use nulls as delimiters in your protocol, since
//       some of the values you send might contain them!)
//
//       For your project, your "rpcgen" program will generate
//       stubs like this one automatically from the idl
//       file. Note that this stub also #includes the 
//       simplefunctions.idl file. Of course, your rpcgen
//       program will change that, as well as the number
//       of functions generated. More importantly, it will
//       generate code to handle function arguments and
//       return values.
//
//       You can structure your stub however you like. This
//       one relies on the container to loop calling 
//       dispatchFunction() until eof is reached, but you
//       can do it other ways. In general, there needs to
//       be some place where you read the stream to see
//       which function to call; how you do that is up to you.
//
//       Copyright: 2012 Noah Mendelsohn
//
// --------------------------------------------------------------

// IMPORTANT! WE INCLUDE THE IDL FILE AS IT DEFINES THE INTERFACES
// TO THE FUNCTIONS WE'RE IMPLEMENTING. THIS MAKES SURE THE
// CODE HERE ACTUALLY MATCHES THE REMOTED INTERFACE

#include "arithmetic.idl"
#include "lotsofstuff.idl"

#include "rpcstubhelper.h"

#include <cstdio>
#include <cstring>
#include <string>
#include "c150debug.h"

using namespace C150NETWORK;  // for all the comp150 utilities 

void get_json();

// ======================================================================
//                             STUBS
//
//    Each of these is generated to match the signature of the 
//    function for which it is a stub. The names are prefixed with "__"
//    to keep them distinct from the actual routines, which we call!
//
//    Note that when functions take arguments, these are the routines
//    that will read them from the input stream. These routines should
//    be generated dynamically from your rpcgen program (and so should the
//    code above).
//
// ======================================================================
  


void __add(string message, int params) {
  //char doneBuffer[5] = "DONE";  // to write magic value DONE + null

  //
  // Time to actually call the function 
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: invoking add()");
  add(1, 2);

  //
  // Send the response to the client
  //
  // If func1 returned something other than void, this is
  // where we'd send the return value back.
  //
  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: returned from  func1() -- responding to client");
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

void __subtract(string json, int params) {
  //char doneBuffer[5] = "DONE";
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

void __multiply(string json, int params) {
  //char doneBuffer[5] = "DONE";
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);

}

void __divide(string json, int params) {
  //char doneBuffer[5] = "DONE";
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}

//
//     __badFunction
//
//   Pseudo-stub for missing functions.
//

void __badFunction(string func_name) {
  //char doneBuffer[5] = "BAD";  // to write magic value DONE + null


  //
  // Send the response to the client indicating bad function
  //

  c150debug->printf(C150RPCDEBUG,"simplefunction.stub.cpp: received call for nonexistent function %s()", func_name);
  //RPCSTUBSOCKET->write(doneBuffer, strlen(doneBuffer)+1);
}



// ======================================================================
//
//                        COMMON SUPPORT FUNCTIONS
//
// ======================================================================

// JSON FUNCS
int get_json_size(char *buffer, unsigned int bufSize);
void get_json(char *buffer, unsigned int bufSize);

// PARSING FUNCS
string get_func_name(string json);
int get_num_params(string json);

// STRING TO CPP FUNCS
int handle_int(string);
float handle_float(string);
string handle_string(string);


//
//                         dispatchFunction()
//
//   Called when we're ready to read a new invocation request from the stream
//

void dispatchFunction() {
  cout << "Dispatched again";
  char JsonSizeBuffer[30];

  // Get the Size of the Json 
  int json_size = get_json_size(JsonSizeBuffer, sizeof(JsonSizeBuffer));

  // Throw Error For Invalid JSON ("Shouldn't be possible?")
  if(json_size == -1)
    throw C150Exception("Finding Json Size Failed");

  // Load the Json into the Buffer
  char JsonBuffer[json_size];
  get_json(JsonBuffer, sizeof(JsonBuffer));

  cout << "Loaded Json:" << JsonBuffer << endl;

  //Save the Json as a string 
  string json_str(JsonBuffer, json_size);
  //Get the function name from json
  string func_name = get_func_name(json_str);
  //Get the num of params from json 
  int params = get_num_params(json_str);

 

  //
  // We've read the function name, call the stub for the right one
  // The stub will invoke the function and send response.
  //
  

  if (!RPCSTUBSOCKET->eof()) {
    if (func_name == "add")
      __add(json_str, params);
    else   if (func_name == "subtract")
      __subtract(json_str, params);
    else   if (func_name == "multiply")
      __multiply(json_str, params);
    else   if (func_name == "divide")
      __divide(json_str, params);
    else
      __badFunction(func_name);
  }
}
                 
//   Important: this routine must leave the sock open but at EOF
//   when eof is read from client. 
//   This function parses the size of the json message from the socket
int get_json_size(char *buffer, unsigned int bufSize) {
  unsigned int i;
  char *bufp;      // next char to read
  ssize_t readlen; // amount of data read from socket

  bufp = buffer;

  for (i=0; i< bufSize; i++) {
    readlen = RPCSTUBSOCKET-> read(bufp, 1);  // read a byte

    // if we hit the first comma that delimits size, parse and
    // convert the size of the json to an int 
    // +1s are to account for delimiter on both ends
    // TODO: clean this up, more error handles, better way to do this?
    if (*bufp == ',') {
      string s_buffer = string(buffer);
      unsigned delim_1 = s_buffer.find(':');
      unsigned delim_2 = s_buffer.find(',');
      string s_size = s_buffer.substr(delim_1 + 1, delim_2 - (delim_1 +1));
      cout << "JSON size: " << s_size << endl;
      return (stoi(s_size));
    }
    bufp++;

    // Error Handle 
    if (readlen == 0) {
    c150debug->printf(C150RPCDEBUG,"simplefunction.stub: read zero length message, checking EOF");
      if (RPCSTUBSOCKET-> eof()) {
        c150debug->printf(C150RPCDEBUG,"simplefunction.stub: EOF signaled on input");
      } else {
      throw C150Exception("simplefunction.stub: unexpected zero length read without eof");
      }
    }  
  }
  // Return Bad Size if Unseen Error
  return -1;   
} 

// This function Puts the JSON String in the Buffer
void get_json(char *buffer, unsigned int bufSize)  {
  unsigned int i;
  char *bufp;      // next char to read
  ssize_t readlen; // amount of data read from socket
  bool readnull;

  bufp = buffer;

  // + 1 is to deal with null termination
  for (i=0; i< bufSize + 1; i++) {
    readlen = RPCSTUBSOCKET-> read(bufp, 1);  // read a byte

    if (readlen == 0) {
      break;
    }
    // check for null and bump buffer pointer
    if (*bufp++ == '\0') {
      readnull = true;
      break;
    }
  }

  // Error Handling 
  if (readlen == 0) {
    c150debug->printf(C150RPCDEBUG,"simplefunction.stub: read zero length message, checking EOF");
    if (RPCSTUBSOCKET-> eof()) {
      c150debug->printf(C150RPCDEBUG,"simplefunction.stub: EOF signaled on input");

    } else {
      throw C150Exception("simplefunction.stub: unexpected zero length read without eof");
    }
  }
  // If we didn't get a null, input message was poorly formatted
    else if(!readnull) 
    throw C150Exception("simplefunction.stub: method name not null terminated or too long");
}

// Ugly Parses the Function Name from Method, Maybe Find 3rd Party Library?
// Probably better way to do this? At Very Least modularize?
string get_func_name(string json) {
  string func_key = "\"method\":";
  unsigned function_pos = json.find(func_key);
  string parsed_json = json.substr(function_pos + func_key.length() + 1, json.npos);
  unsigned delim = parsed_json.find('\"');
  return parsed_json.substr(0, delim); 
}

// Ugly Parses the Num of Params from Method, Maybe Find 3rd Party Library?
// Probably better way to do this? At Very Least modularize?
int get_num_params(string json) {
  string p_num_key = "\"param_count\":";
  unsigned function_pos = json.find(p_num_key);
  string parsed_json = json.substr(function_pos + p_num_key.length() + 1, json.npos);
  unsigned delim = parsed_json.find('\"');
  return stoi(parsed_json.substr(0, delim)); 
}


// Basic Function That Handle Basic Conversions 
// from string to CPP types

int handle_int(string int_string) {
  return stoi(int_string);
}

string handle_string(string s_string) {
  return s_string;
}

float handle_float(string float_string) {
  return stof(float_string);
}




