#-*- encoding:utf-8 -*-
import sys
import matplotlib.pyplot as plt

def read_data(filename, t):
    f = open(filename, "r")
    data = []
    dataFull = [[], []]

    for line in f.readlines():
        if t == 'D' or t == 'V':
            data.append(line.split("\t")[1])
        else:
            dataFull[0].append(line.split("\t")[0])
            dataFull[1].append(line.split("\t")[1])

    if t == 'D' or t == 'V':
        return data
    else:
        return dataFull

def plot(data, t):
    if t == 'D':
        plt.plot(data, 'b', linewidth = 2)
        plt.title(u'Dirección del viento')
        plt.ylabel(u'Grados [º]')
    elif t == 'V':
        plt.plot(data, 'r', linewidth = 2)
        plt.title(u'Velocidad del viento')
        plt.ylabel(u'Velocidad [km/h]')
    else:
        fig, ax1 = plt.subplots()
        ax1.plot(data[0], 'b', linewidth = 2, label = u'Velocidad')
        ax1.set_ylabel(u'Velocidad [km/h]')
        ax1.legend(loc = 0)

        ax2 = ax1.twinx()
        ax2.plot(data[1], 'r', linewidth = 2, label = u'Dirección')
        ax2.set_ylabel(u'Velocidad [km/h]')
        ax2.set_ylabel(u'Grados [º]')
        ax2.legend(loc = 1)

        plt.title(u'Dirección y velocidad del viento')

    plt.grid(True)
    plt.show()

if __name__ == '__main__':
    filename = sys.argv[1]
    t = filename[4]
    data = read_data(filename, t)
    plot(data, t)
