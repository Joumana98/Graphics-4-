#include "../std_lib_facilites.h"
#include "Simple_window.h"
#include "Graph.h"

constexpr xmax=600;
constexpr ymax=600;

constexpr int orig_x=300;
constexpr int orig_y=300;
constexpr Point orig{orig_x,orig_y};

constexpr xscale=30;
constexpr yscale=30;

constexpr r1=-10;
constexpr r2=11;
constexpr pcount=40;


int main()
{
    using namespace Graph_lib;

    Simple_window win{Point{20,20},xmax,ymax,"My canvas"};

    //Axes
    Axis xs{Axis::x,Point{20,orig_y},xmax-40,(xmax-40)/xscale,"1 notch=30"};
    Axis ys{Axis::y,Point{orig_x,ymax-20},ymax-40,(ymax-40)/yscale,"1 notch=30"};
    xs.set_color(Color::red);
    ys.set_color(Color::red);
    win.attach(xs);
    win.attach(ys);

    //Functions
    Function f1{[](double x){return cos(x);},r1,r2,orig,40,xscale,yscale};
    Function f2{[](double x){return sin(x);},r1,r2,orig,40,xscale,yscale};
    Function f3{[](double x){return sin(x)+cos(x);},r1,r2,orig,40,xscale,yscale};
    Function f4{[](double x){return sin(x)*sin(x)+cos(x)*cos(x);},r1,r2,orig,40,xscale,yscale};
    win.attach(f1);
    win.attach(f2);
    win.attach(f3);
    win.attach(f4);

    //Labels
    Text t1{Point{20,ymax+50,"cos(x)"};
    Text t2{Point{20,ymax-50,"sin(x)"};
    Text t3{Point{20,ymax-100,"sin(x)+cos(x)"};
    Text t4{Point{20,ymax-200,"sin(x)*sin(x)+cos(x)*cos(x)"};
    win.attach(t1);
    win.attach(t2);
    win.attach(t3);
    win.attach(t4);


    win.wait_for_button();
    return 0;
}
