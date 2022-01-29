class Solution {
public:
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r= radius;
        x= x_center;
        y=y_center;
    }
    //use sqrt for even distri
    vector<double> randPoint() {
       double angle = (double)rand()/RAND_MAX * 2 * M_PI,
        len = sqrt((double)rand()/RAND_MAX )*r,
        oppside= cos(angle)*len,
        adjside = sin(angle)*len;
        return {x+adjside,y+oppside};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */