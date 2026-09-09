/* #include <bits/stdc++.h>  
using namespace std;  

void findNthPerson(int n) {  
    vector<int> q;   
    vector<int> accept;   

     
    for (int i = 0; i < 10000; ++i) {  
        q.push_back(i + 2);  
    }  

    int currentIndex = 0;  

    while (accept.size() < n) {    
        int current = q[currentIndex];  
        accept.push_back(current);  
  
        vector<int> new_q;  
        for (int i = 0; i < q.size(); i++) {   
            if ((i - currentIndex) % current != 0) {  
                new_q.push_back(q[i]);  
            }  
        }  
        q = new_q;  
  
        currentIndex = 0;  
    }  

    cout << accept.back();  
}  

int main() {  
    int n;  
    cin >> n;  
    findNthPerson(n);   
    return 0;  
}   */
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int> q;
    vector<int> check;
    cin >> n;
    for(int i=2;i<=10005;i++){
        q.push_back(i);
    }

    while(check.size() < n){
        auto curr = q.begin();
        check.push_back(*curr);
        vector<int> new_q;
        for(auto i=q.begin();i!=q.end();i++){
            if((i-q.begin())%*curr != 0){
                new_q.push_back(*i);
            }
        }
        q=new_q;
    }

    cout << check[n-1];
    return 0;
}