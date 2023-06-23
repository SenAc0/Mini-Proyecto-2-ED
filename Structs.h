//point
//node
struct Point {
    double x;
    double y;
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    Point()
    {
        x = 0;
        y = 0;
    }
};
struct Node {
    Point pos;
    int data;
    Node(Point _pos, int _data)
    {
        pos = _pos;
        data = _data;
    }
    Node() { data = 0; }
};
struct Data{
    string city;
    double population;
    Data(){
        city = ' ';
        population = 0;
    }
    Data(string _city, double _population){
        city = _city;
        population = _population;
    }
};