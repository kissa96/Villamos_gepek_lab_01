import matplotlib.pyplot as plt
import numpy as np

with open('resistance_values.txt') as f:
    lines = f.readlines()
    for i in range(3):
        lines.pop(0)
    x = [sbstr.strip().split('\t')[0] for sbstr in lines]
    y = [round(float(sbstr.strip().split('\t')[1]), 4) for sbstr in lines]
    plt.title('Coil resistance ')
    plt.xlabel('Temperature[C]')
    plt.ylabel('Resistance[ohms]')
    plt.xticks(rotation=90)
    plt.plot(x, y)
    plt.show()
