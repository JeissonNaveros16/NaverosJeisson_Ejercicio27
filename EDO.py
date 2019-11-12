import numpy as np
import matplotlib.pyplot as plt

data1a = np.loadtxt("valoresEuler1.dat")
data1b = np.loadtxt("valoresEuler2.dat")
data1c = np.loadtxt("valoresEuler3.dat")
data2a = np.loadtxt("valoresImplic1.dat")
data2b = np.loadtxt("valoresImplic2.dat")
data2c = np.loadtxt("valoresImplic3.dat")

plt.figure(figsize=(15,8))
plt.title("Solución de EDO")
subplot(1,2,1)
plt.plot(data1a[:,0], data1a[:,1], label = "Para WDeltaT = 0.1" )
plt.plot(data1b[:,0], data1b[:,1], label = "Para WDeltaT = 0.01" )
plt.plot(data1c[:,0], data1c[:,1], label = "Para WDeltaT = 1" )
plt.xlabel("Tiempo")
plt.ylabel("y(T) (hallado explicitamente)")
plt.legend()

subplot(1,2,2)
plt.plot(data2a[:,0], data2a[:,1], label = "Para WDeltaT = 0.1" )
plt.plot(data2b[:,0], data2b[:,1], label = "Para WDeltaT = 0.01" )
plt.plot(data2c[:,0], data2c[:,1], label = "Para WDeltaT = 1" )
plt.xlabel("Tiempo")
plt.ylabel("y(T) (hallado implicitamente)")
plt.legend()

plt.savefig("EDO.png")