#include <iostream>
#include <functional>
#include <vector>
#include <CPP/test.h>
int main()
{
    using Kernel = typename Manifold::Point<float>;
    using Point_Cloud = typename std::vector<Kernel>;
    using ManifoldDist = typename Manifold::ManifoldDist<Kernel>;
    using FT = typename Kernel::FT;
    using Point_d = typename Kernel::Point_d;
    using  DistFunc = typename ManifoldDist::DistFunc;
    DistFunc distfunc = Manifold::dencedistance<FT, Point_d>;
    ManifoldDist dence(distfunc);
    Point_Cloud points;
    points.emplace_back(1.1, 2.);
    points.emplace_back(2., 1.5);
    Point_d point_1 = (*(points.begin()))();
    Point_d point_2 = (*(points.end()))();
    std::cout << dence.get_distfunc()(point_1,point_2) << std::endl;
};