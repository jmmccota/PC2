
#ifndef SPLITSTRING_H
#define	SPLITSTRING_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class SplitString : public string {

    vector<string> flds;

public:

	SplitString(string s)  : string(s){
	}
    vector<string>& split(char delim, int rep = 0);
};

#endif	/* USUARIO_H */

