import os

os.system("del resistance_values.txt")
os.system("g++ vg_res_calc.cpp -o temp_run.exe")
os.system("temp_run.exe")
os.system("py diagram.py")
os.system("del temp_run.exe")
