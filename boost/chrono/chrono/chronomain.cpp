#include <iostream>
#include <boost/chrono/chrono_io.hpp>
#include <boost/chrono/floor.hpp>
#include <boost/chrono/round.hpp>
#include <boost/chrono/ceil.hpp>

int main()
{
    using namespace boost::chrono;
    milliseconds ms(2500);
    std::cout << floor<seconds>(ms) << '\n';
    std::cout << round<seconds>(ms) << '\n';
    std::cout << ceil<seconds>(ms) << '\n';
    ms = milliseconds(2516);
    typedef duration<long, boost::ratio<1, 30> > frame_rate;
    std::cout << floor<frame_rate>(ms) << '\n';
    std::cout << round<frame_rate>(ms) << '\n';
    std::cout << ceil<frame_rate>(ms) << '\n';

    return 0;
}