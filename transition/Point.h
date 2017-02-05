class Point {
   private:
      // these attributes are not visible 
      // outside of the class
      double _x;
      double _y;

   public:
      Point();
      Point(double x, double y);
      // using const here meaans 
      // the function won't change 
      // the value of any attributes (must go after)
      //double getX() const; 
      double getX(); 
      double getY() const;
      void setX(double val);
      void setY(double val);
};
