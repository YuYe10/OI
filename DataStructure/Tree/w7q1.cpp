#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class File{
public:
    int name;
    int size;

    File() : name(0), size(0) {}
    File(int name_, int size_) : name(name_), size(size_) {}

    
    bool operator <(const File& b) const {
            if (size != b.size) return size > b.size;
            return name < b.name;
        };
};

map<int, set<File>> folders_manager;

void addFile(int folder, int name, int size){
    auto& files = folders_manager[folder];

    files.erase(File(name, 0));

    files.insert(File(name, size));
}

void deleteFile(int folder, int name){
    auto& files = folders_manager[folder];
    files.erase(File(name, 0));
}

void printFilesAscendBySize(int folder, int k){
    if(folders_manager.find(folder) == folders_manager.end() || folders_manager[folder].empty()){
        cout << endl;
        return;
    }
    auto& files = folders_manager[folder];
    int count = 0;
    for(const auto& file : files){
        if(count > 0) cout << ' ';
        if (count++ >= k) break;
        cout << file.name;
    }
    cout << endl;
}

void printFilesDescendByName(int folder, int k){
    if(folders_manager.find(folder) == folders_manager.end()){
        cout << endl;
        return;
    }
    auto& files = folders_manager[folder];
    int count = 0;
    auto it = files.rbegin(); // 从set的末尾开始迭代，即最大的元素
    for(; it != files.rend() && count < k; it++ , count++){
        if(count > 0) cout << ' ';
        cout << it->name;
    }
    cout << endl;
}

int main(){
    int Q;
    cin >> Q;
    while(Q--){
        int op, folder, name, size, k;
        cin >> op;
        if(op == 1){
            cin >> folder >> name >> size;
            addFile(folder, name, size);
        }else if (op == 2){
            cin >> folder >> name;
            deleteFile(folder, name);
        }else if (op == 3){
            cin >> folder >> k;
            printFilesAscendBySize(folder, k);
        }else if (op == 4){
            cin >> folder >> k;
            printFilesDescendByName(folder, k);
        }
    }
    return 0;
}