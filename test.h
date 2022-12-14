#include <iostream>
#include <functional>
#include <vector>
#include <array>

namespace Manifold
{
    template <typename Field>
    class Point
    {
    public:
        using FT = Field;
        using Point_d = typename std::array<FT, 2>;
        Point_d operator()(void)
        {
            Point_d point({this->_x, this->_y});
            return point;
        };
        Point(Field x, Field y) : _x(x), _y(y){};

    private:
        Field _x;
        Field _y;
    };
    /*Kernel is Point_d*/
    template <typename Kernel>
    class ManifoldDist
    {
    public:
        using FT = typename Kernel::FT;
        using Point_d = typename Kernel::Point_d;
        using DistFunc = typename std::function<FT(const Point_d &, const Point_d &)>;
        DistFunc get_distfunc()
        {
            return _distance;
        };
        ManifoldDist(DistFunc distance) : _distance(distance){};
    private:
        DistFunc _distance;
    };

    template <typename FT, typename Point_d>
    FT dencedistance(const Point_d &point_1, const Point_d &point_2)
    {
        return (FT)0;
    };
}; // namespace Manifold
