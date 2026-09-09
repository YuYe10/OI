/* #include <bits/stdc++.h>
using namespace std;

vector<string> operation;
stack<string> write;
stack<string> undo;
stack<string> output;

void WordOperations(int n){
    for(const auto&op : operation){
        if(op.substr(0,6) == "input "){
            string input_contents = op.substr(6);

            if(input_contents.length() >= 1 && input_contents.length() <= 30){
                write.push(input_contents);
                while(!undo.empty()){
                    undo.pop();
                }
            }
        }else if(op == "ctrl+z"){
            if(!write.empty()){
                undo.push(write.top());
                write.pop();
            }
        }else if(op == "ctrl+y"){
            if(!undo.empty()){
                write.push(undo.top());
                undo.pop();
            }
        }
    }

    if(!write.empty()){

        while(!write.empty()){
            output.push(write.top());
            write.pop();
        }

        while(!output.empty()){
            cout << output.top() << " ";
            output.pop();
        }

    }else{
        cout << "No output";
   }
}
int main(){
    int n;
    int flag = 1;
    scanf("%d",&n);
    while(n--){
        string x;
        if(flag)getchar();
        flag = 0;
        getline(cin, x);
        operation.push_back(x);
    }

    WordOperations(n);

    return 0;
} */
#include <bits/stdc++.h>
using namespace std;
vector<string> ops;
stack<string> w;
stack<string> undo;
stack<string> out;

int main(){
    int n;int flag = 1;
    cin >> n;

    while(n--){
        string x;
        if(flag) getchar();
        flag = 0;
        getline(cin, x);
        ops.push_back(x);
    }

    for(auto op:ops){
        if(op.substr(0,6) == "input "){
            string msg = op.substr(6,op.size());
            if(msg.length()>=1 && msg.length() <= 30){
                w.push(msg);
                undo = stack<string>();
            }
        }else if(op=="ctrl+z"){
            if(!w.empty()){
                undo.push(w.top());
                w.pop();
            }
        }else if(op=="ctrl+y"){
            if(!undo.empty()){
                w.push(undo.top());
                undo.pop();
            }
        }
    }

    if(!w.empty()){    
        while(!w.empty()){
            out.push(w.top());
            w.pop();
        }
        while(!out.empty()){
            cout << out.top() << ' ';
            out.pop();
        }
    }else{
        cout << "No output";
    return 0;
    }
}