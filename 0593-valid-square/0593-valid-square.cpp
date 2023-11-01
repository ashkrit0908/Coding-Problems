class Solution {
public:
    int sideSquare(vector<int>& a, vector<int>& b) {

        int side=0;
        side=((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));

        return side;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        vector<int> sides;

        sides.push_back(sideSquare(p1, p2));
        sides.push_back(sideSquare(p2, p3));
        sides.push_back(sideSquare(p3, p4));
        sides.push_back(sideSquare(p4, p1));
        sides.push_back(sideSquare(p1, p3));
        sides.push_back(sideSquare(p2, p4));

        sort(sides.begin(), sides.end());

        return (sides[0]>0 && sides[0]==sides[3] && sides[4]==sides[5]);
    }
};