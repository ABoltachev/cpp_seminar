#include "TestLib.hpp"

int main() {
    TestLib::Logger *logger = TestLib::initLogger("test.log.bin", true);
    TestLib::print(*logger, 10, 3.14);
    return 0;
}

