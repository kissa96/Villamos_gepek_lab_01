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

#ifndef RESISTANCE_CALC_C_H
#define RESISTANCE_CALC_C_H

#include <iostream>
#include <fstream>
#include <sstream>

class resistance_calc_t{

public:
    void set_params(cfg_t cfg_param) {
        cfg = cfg_param;
    }
    cfg_t get_params() {
        return cfg;
    }
    void calculate_values(unsigned int T_cold, double R_cold, unsigned int n){
        calc_res_val_iterate(T_cold, R_cold, n);
    }

private:
    cfg_t cfg;
    double calc_res_val(unsigned int T_cold, unsigned int T_hot, double R_cold){
        //casting manually
        double t_cold_local = (double)T_cold;
        double t_hot_local  = (double)T_hot;
        double r_cold_local = (double)R_cold;
        double r_hot_local;
        t_hot_local  = t_hot_local + 235;
        t_cold_local = t_cold_local + 235;
        r_hot_local  = (t_hot_local/t_cold_local) * r_cold_local;
        return r_hot_local;
    }
    void calc_res_val_iterate(unsigned int T_cold, double R_cold, unsigned int n){
        double temp_resistance_val;
        std::string s ="R_hot values: \n \nT[C]\tR_hot[ohms]\n";
        std::ofstream fout;
        for(unsigned int i=T_cold; i<(n+T_cold) ; i++){
            temp_resistance_val = calc_res_val(T_cold,i+1,R_cold);
            s += std::to_string(i+1);
            s += "\t";
            s += std::to_string(temp_resistance_val);
            s += "\n";
        }
        if(cfg.enable_console_printing)
            std::cout << s;
        if(cfg.enable_file_printing){
            fout.open("./resistance_values.txt");
            fout << s;
            fout.close();
        }
        return;
    }
};

#endif //RESISTANCE_CALC_C_H
