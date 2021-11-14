/*
Copyright (c) 2021 Attila Kiss, Peter Kapin, Benjamin P. Vizi, Olivia Nagy, David Horvath, Bence Pirk, Bence Szarka

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <iostream>
#include <fstream>
#include <sstream>

#include "Types/Typedefs/resistance_calc_types.h"
#include "Types/Classes/resistance_calc_c.h"

int main()
{
    cfg_t resistance_cfg;

    resistance_cfg.enable_console_printing = 1;
    resistance_cfg.enable_file_printing = 1;
    resistance_calc_t resistance_calc;
    resistance_calc.set_params(resistance_cfg);

    resistance_calc.calculate_values(24, 1.8, 100);

    return 0;
}
