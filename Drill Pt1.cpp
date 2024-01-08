#include "Simple_window.h"
#include "Graph.h"
#include "../std_lib_facilites.h"

constexpr Point orig{300,300};
constexpr xscale=20;
constexpr yscale=20;
constexpr r1=-10;
constexpr r2=11;

double sloping_cos(double x)
{
    return cos(x)+x/2;
}

int main()
{
    using namepace Graph_lib;

    Simple_window win{Point{20,100},600,600,"Function graphs"};

    Axis xs{Axis::x,Point{100,300},400,20,"1 == 20 pixels"};
    Axis ys{Axis::y,Point{300,100},400,20,"1 == 20 pixels"};
    xs.set_color{Color::red};
    ys.set_color{Color::red};
    win.attach{xs};
    win.attach{ys};

    Function f1{[](double x){return 1;},r1,r2,orig,400,xscale,yscale};
    Text t1{Point{100,300-20},"one"};
    win.attach(f1);
    win.attach(t1);

    Function f2{[](double x){return x/2;},r1,r2,orig,400,xscale,yscale};
    Text t2{Point{200,600-200-20},"x/2"};
    win.attach(f2);
    win.attach(t2);

    Function f3{[](double x){return x*x;},r1,r2,orig,400,xscale,yscale};
    Text t3{Point {300-100,20},"x*x"};
    win.attach(f3);
    win.attach(t3);

    Function f4{[](double x){return cos(x);},r1,r2,orig,400,xscale,yscale};
    f4.set_color(Color::blue);
    Text t4{Point{20,300-20-20},"cos(x)"};
    win.attach(f4);
    win.attach(t4);

    Function f5{sloping_cos,r1,r2,orig,400,xscale,yscale};
    Text t5{Point{400,200-20},"Sloping cosine"};
    win.attach(f5);
    win.attach(t5);


    win.wait_for_button();

    return 0;
}
