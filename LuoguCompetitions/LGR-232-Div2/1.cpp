#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    getline(cin, a);

    for (char &c : a) c = tolower(c);

    int cnt = 0;

    for(int i = 0; i < a.length(); ++i){
        //if(a.find('.',0)==EOF) 
            //return 0;
        
        //if (!isalpha(a[i]) && a[i] != '.') 
            //return 0;

        //if(a[i] == '.' && (i == 0 || i == a.length() - 1)) 
            //return 0;

        //if(i<a.length()-1)
            //if(a[i]=='.' && a[i+1]=='.')
                //return 0;

        if(a[i]=='.'){
            cnt++;
            if(cnt >= 1){
                string t = string{a[i+1], a[i+2], a[i+3]};
                string t1 = string{a[i+5], a[i+6]};
                if(t == "edu" && t1 == "cn"){
                    cout << i+7 << ' ';
                }
            }
        }
    }
    
    return 0;
}