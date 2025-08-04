#include<iostream>
using namespace std;
class TV{
    int mn, pz, ss;
    public:
    friend istream &operator>>(istream &, TV&);
    friend ostream &operator<<(ostream &, TV&);
};

istream &operator>>(istream &din, TV &t)
{
    int e;
    cout<<"\nEnter the model no. , price , screen size : ";
    din>>t.mn>>t.pz>>t.ss;

try{
    if(t.mn>9999 || t.pz<0 || t.pz>400000 || t.ss>70 || t.ss<12)
        throw e;
}

catch(int e){
    cout<<"\nException handled.";
    t.mn=0;
    t.pz=0;
    t.ss=0;
}
return din;
}
ostream &operator<<(ostream &dout, TV &t){
    cout<<"\nTV Details...";
    cout<<"\nModel number : "<<t.mn;
    cout<<"\nPrice : "<<t.pz;
    cout<<"\nScreen size : "<<t.ss;
    return dout;
}

int main(){
    TV t;
    cin >> t;
    cout << t;
return 0;
}
