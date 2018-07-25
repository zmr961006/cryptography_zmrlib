/*************************************************************************
	> File Name: number_to_charindex.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年07月25日 星期三 15时14分15秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

#define LEN 1024


class number_to_charindex{

public:

    char buff[LEN];
    int A;
    int B;

    number_to_charindex(){

    }


    void trans_run(){
        
        std::string buf;
        std::cin >> buf;
        for(int i = 0; i < buf.length();i++){
            func(buf[i]);
        }

    }
    
    void func(char a){
        
        if(a == ' '){
            std::cout << " ";
        }else{
            
            if(((int)a) >= 65 && ((int)a) <= 90){ 
                int index = (((int)(a)) - 65);
                int c = ENC(index);
                DEC(c);
            }

            if(((int)a) >= 97){
                int index = (((int)(a)) - 97);
                int c = ENC(index);
                DEC(c);
            }

        }

    }
    
    int ENC(int index){
        
        
        std::cout << "ENC:" << ((A*index + B)%26) << std::endl;
        return ((A*index + B)%26);

    }

    int DEC(int index){
    
        int res = ((((minusatom(A,26)) * (index - B))) % 26);
        if(res < 0){            //c++ 不是时钟模运算
            res += 26;
        }
        std::cout << "DEC:" << res << std::endl;
        return res;
    }

    int minusatom(int a,int b){
        
        int index = 1;
        while(((a * index) % b) != 1){
            index++;
        }
        //std::cout << "niyuan:" << index << std::endl;
        return index;
    }
    


};


int main(){


    number_to_charindex  test;
    test.A = 11;
    test.B = 23;
    test.trans_run();



}

