EDO.png : valoresEuler1.dat valoresEuler2.dat valoresEuler3.dat valoresImplic1.dat valoresImplic2.dat valoresImplic3.dat EDO.py
	python EDO.py

valoresEuler1.dat valoresEuler2.dat valoresEuler3.dat valoresImplic1.dat valoresImplic2.dat valoresImplic3.dat: EDO.x
	./EDO.x

EDO.x : EDO.cpp
	c++ EDO.cpp -o EDO.x