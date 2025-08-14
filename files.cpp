#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string source = "file1.csv";
    string destination = "file2.csv";
    // open source file in binary mode
    ifstream file1(source , ios::binary | ios::ate);
    //open dest file in binary mode
    ifstream file2(destination , ios::binary | ios::ate);
    //source file size
    streamsize size_file1=file1.tellg();
    // dest file size
    streamsize size_file2=file2.tellg();
    // source file doesnot exist or empty
    if(!file1.is_open()){
       cout<<"Source file is missing\n ";
    }
    else if(size_file1==0){
        cout<<"Source is empty\n";
    }
    // destination file is missing ,create new file and copy data using read buffer
    else if(!file2.is_open()){
        cout<<"destination file is missing\ncreate and copy ";
        file1.seekg(0,ios::beg);
        ofstream file2(destination,ios::binary);
        file2<<file1.rdbuf();
    }
    // destination file is empty , copy data using read buffer
    else if(size_file2==0){
         cout<<"Destination is empty\n";
         file1.seekg(0,ios::beg);
         ofstream file2(destination,ios::binary);
         file2 <<file1.rdbuf();
    }
    // file 2 contains date then delete and over write
    
    else{
        file1.seekg(0, ios::beg);
        ofstream file2(destination ,ios::binary| ios::trunc);
        file2 << file1.rdbuf();
        cout<<"Destination file is over written";
    }
   
    return 0;
}