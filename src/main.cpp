#include <iostream>

#include "main.hpp"

int main()
{
    try
    {
        auto app = Application{};
        app.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "CaveExplorer detected an error: " << e.what() << '\n';
        std::cerr << "Due to this error the CaveExplorer unfortunately needs to terminate." << std::endl;
    }
}
