class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> ans;
        queue<int> r;
        queue<int> d;
        for (int i = 0; i < n; i++) {
            ans.push(i);
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }
        while(ans.size()>1){
            if(senate[ans.front()]=='X') ans.pop();
            else if(senate[ans.front()]=='R'){
                if(d.size()==0) return "Radiant"; 
                else if(d.size()>0){  /// take rights of next d
                    senate[d.front()]='X';
                    d.pop();
                    ans.push(ans.front());
                    ans.pop();
                    r.push(r.front());
                    r.pop();
                }
            }
            else if(senate[ans.front()]=='D'){
                if(r.size()==0) return "Dire"; 
                else if(r.size()>0){   /// take rights of next r
                    senate[r.front()]='X';
                    r.pop();
                    ans.push(ans.front());
                    ans.pop();
                    d.push(d.front());
                    d.pop();
                }
            }
        }
        return (r.size()>0)? "Radiant":"Dire";
    }
};