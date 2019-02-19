#include<string>
using std::string;
#include<vector>
using std::vector;
#include<algorithm>
using std::transform;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
using std::ostringstream;
// any other includes you need
#include "proj06_functions.h"
#include<iostream>
#include<fstream>
using namespace std;
// your functions after this

string to_binary(int val)
{
  string binary_str="";
  if (val < 1 or val>255)
    binary_str ="00000000";
  else
  {
    while(val!=0)
    {
        if (val%2 == 0)
        {
            binary_str = "0" + binary_str;
            val = val / 2;
        }
        else
        {
            binary_str = "1" + binary_str;
            val = val / 2;
        }
    }//End of while loop
    while(binary_str.size()!=8)
    {
        binary_str = "0" + binary_str;
    }//End of while loop
  }//End of Else block
  return binary_str;
}//End of to_binary Function

int next_val(const vector<int> &v, const string &rule_binary_string)
{
    int n_val;
    vector<int> r7{1,1,1};
    vector<int> r6{1,1,0};
    vector<int> r5{1,0,1};
    vector<int> r4{1,0,0};
    vector<int> r3{0,1,1};
    vector<int> r2{0,1,0};
    vector<int> r1{0,0,1};
    vector<int> r0{0,0,0};
    if(v==r7)
    {
        n_val=rule_binary_string[0]-'0';
    }
    if(v==r6)
    {
        n_val=rule_binary_string[1]-'0';
    }
    if(v==r5)
    {
        n_val=rule_binary_string[2]-'0';
    }
    if(v==r4)
    {
        n_val=rule_binary_string[3]-'0';
    }
    if(v==r3)
    {
        n_val=rule_binary_string[4]-'0';
    }
    if(v==r2)
    {
        n_val=rule_binary_string[5]-'0';
    }
    if(v==r1)
    {
        n_val=rule_binary_string[6]-'0';
    }
    if(v==r0)
    {
        n_val=rule_binary_string[7]-'0';
    }
    
    return n_val; 
}

vector<int> one_iteration(const vector<int> &v, const string &rule_binary_string)
{
   vector<int> ret_vec;
   vector<int> temp_v = v;
   temp_v.push_back(0);
   temp_v.insert(temp_v.begin(), 0);
   for(unsigned int i = 1; i < temp_v.size()-1; i++){
       vector<int> temp;
       temp.push_back(temp_v[i-1]);
       temp.push_back(temp_v[i]);
       temp.push_back(temp_v[i+1]);
       int x = next_val(temp, rule_binary_string);
       ret_vec.push_back(x);
   }
   return ret_vec;
    
}

string vector_to_string(const vector<int> &v)
{
    ostringstream oss;

    if (!v.empty())
    {
        std::copy(v.begin(), v.end()-1, std::ostream_iterator<int>(oss, ","));
        oss << v.back();
    }
    string n_str = oss.str();
    return n_str;
}

void read_vector(vector<int> &v, string fstring)
{
   if(v.size()==0)
   {
        ifstream in_file(fstring);
        int x;
        if(in_file){
            while(in_file >> x){
                v.push_back(x);
            }
        }
        if(in_file.is_open())
            in_file.close();
   }
}

// a freebie!
// takes in a vector of 0,1
// outputs a string of '_' or '*'
string pretty_print(vector<int> & v){
  ostringstream oss;
  transform(v.begin(), v.end(), ostream_iterator<char>(oss),
	    [] (int i) {
	      return (i==0) ? '_' : '*';
	    }
	    );
    return oss.str();
}
