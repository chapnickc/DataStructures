class Point {


    private:
        // these attributes are 
        // not visible outside of 
        // the classs
        double _x;
        double _y;

    public:
        Point();
        // using const here meaans 
        // the function won't change 
        // the value of any attributes (must go after)
        double getX() const; 
        double getY() const;
        void setX(double val);
        void setY(double val);

};
