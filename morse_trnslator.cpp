#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

int main(){
    cout<<"!--WELCOME TO MORSE TRANSLATOR--!"<<endl;
    cout<<"--We are using 'Full stop (.)' as 'Dot'--"<<endl;
    cout<<"--We are using 'Minus (-)' as 'dash'---"<<endl;
    cout<<"--Letters have 1 space between them--"<<endl;
    cout<<"--Words have 2 space between them--"<<endl;
    cout<<"======================="<<endl;
    cout<<"======================="<<endl;


    vector<string>myStrings;
    vector<string>morse_code;
    string morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..","--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-","-.--", "--.."," "};
    char alphabets[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K','L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V','W', 'X', 'Y', 'Z'};
    int x=1;
    int pos=0;
    string letter;
    string message;
    string input;
    string code;
    char space=' ';
    int n;

    while (x){
        cout<<"   1. English to Morse "<<endl;
        cout<<"   2. Morse to English "<<endl;
        cout<<"   3. QUIT! "<<endl;
        cout<<"Choose your option: ";
        cin >>n;
        cin.ignore();
        if (n==1){
            cout<<"====English to Morse===="<<endl;
            cout<<"Enter English text: ";
            getline(cin,input);
            transform(input.begin(), input.end(), input.begin(),::toupper);
            for (int i=0;i<input.length();i++){
                if (input[i]==' '){
                        code=space;
                        morse_code.push_back(code);
                        morse_code.push_back(code);
                        continue; 
                    }
                for (int j=0;j<36;j++){
                    if (input[i]==alphabets[j]){
                        code=morse[j];
                        morse_code.push_back(code);
                        code=space;
                        morse_code.push_back(code);
                    }
                }
            }
            cout<<"Encoded to Morse: ";
            for (const auto& str : morse_code) {
            cout << str;
            }
            cout<<'\n';
        }
        else if (n==2){
            cout<<"====Morse to English===="<<endl;
            cout<<"Enter Morse Code: ";
            getline(cin,input);
            for (int i=0;i<input.length();i++){
                if (input[i]==' '&& input[i+1]==' '){           
                    letter=input.substr(pos,(i-pos));
                    pos=i+2;
                    i++;
                    for (int j=0;j<36;j++){
                        if (morse[j]==letter){
                            message=alphabets[j];
                            myStrings.push_back(message);
                        }
                    }
                    message=space;
                    myStrings.push_back(message);
                }
                else if (input[i]==' '){
                    letter=input.substr(pos,(i-pos));
                    pos=i+1;
                    for (int j=0;j<36;j++){
                        if (morse[j]==letter){
                            message=alphabets[j];
                            myStrings.push_back(message);
                        }
                    }
                }
                else if (i==input.length()-1){
                    letter=input.substr(pos,(i+1-pos));
                    for (int j=0;j<36;j++){
                        if (morse[j]==letter){
                            message=alphabets[j];
                            myStrings.push_back(message);
                        }
                    }
                }
                else {
                    continue;
                }
            }
            cout<<"Decoded from Morse: ";
            for (const auto& str : myStrings) {
                cout << str;
            }
            cout<<'\n';
        }
        else if (n==3){
            x=0;
        }
        else{
            cout<<"Invalid Input!"<<endl;
        }
    }
    cout<<"==== Thanks For Using Our Converter ===="<<flush;
}