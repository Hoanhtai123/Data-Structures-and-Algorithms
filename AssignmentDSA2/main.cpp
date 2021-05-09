#include <stdio.h>
#include "main.h"
#include "Cache.h"
#include "Cache.cpp"

Data* getData(string s) {
	stringstream ss(s);
	int idata;
    float fdata;
    if (ss >> idata) 
		return new Int(idata);
    else if (ss >> fdata)
    	return new Float(fdata);
    else if (s.compare("true") || s.compare("false"))
    	return new Bool(s.compare("true"));
    else {
		s.resize(s.size()-1);
		return new Address(stoi(s));
	}
    	
}
void simulate(string filename,Cache* c)
{
  ifstream ifs;
  ifs.open(filename, std::ifstream::in);
  string s;
  while (getline(ifs, s))
  {
    stringstream ss(s);
    string code,tmp;
    ss >> code;
    int addr;
    Elem* tempp;
    switch (code[0]) {
    	case 'R': //read
			    ss >> addr; 
    			Data* res;
				res = c->read(addr);
    			if (res == NULL) {
    				ss >> tmp;
                    if (tmp == "10") {
                        tempp = c->put(addr, getData(tmp));
                        if (tempp != NULL) {
                            delete tempp;
                        }
                    }
                    else {
                        tempp = c->put(addr, getData(tmp));
                        if (tempp != NULL) {
                            delete tempp;
                        }
                    }
    			} else {
					cout << res->getValue() << endl;
				}
    			break;
        case 'U': //put
                ss >> addr;
                ss >> tmp;
                tempp = c->put(addr, getData(tmp));
                if (tempp != NULL) {
                    delete tempp;
                }
                break;
    	case 'W': //write
                ss >> addr;
    			ss >> tmp;
                if (tmp == "29") {
                    tempp = c->write(addr, getData(tmp));
                    if (tempp != NULL) {
                        delete tempp;
                    }
                }
                else {
                    tempp = c->write(addr, getData(tmp));
                    if (tempp != NULL) {
                        delete tempp;
                    }
                }
    			break;
    	case 'P': // print
    			cout << "Print queue\n";
    			c->print();
    			break;
    	case 'E': // preorder
    			cout << "Print AVL in preorder\n";
    			c->preOrder();
    			break;
    	case 'I': // inorder
    			cout << "Print AVL in inorder\n";
    			c->inOrder();
    			break;
    }
  }
}
int main(int argc, char* argv[]) {
	Cache* c = new Cache(MAXSIZE); 
  	//const char *fileName = argv[1];
    simulate("test3.txt",c);
  	delete c;
	return 0;
}
