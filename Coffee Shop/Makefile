CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o product.o donut.o java.o customer.o order.o store.o  mainwin.o
	${CXX} ${CXXFLAGS} -o main main.o product.o donut.o java.o order.o store.o customer.o mainwin.o $(GTKFLAGS)
main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp $(GTKFLAGS)
product.o: product.cpp *.h
	${CXX} ${CXXFLAGS} -c product.cpp
donut.o: donut.cpp *.h
	${CXX} ${CXXFLAGS} -c donut.cpp
java.o: java.cpp *.h
	${CXX} ${CXXFLAGS} -c java.cpp
customer.o: customer.cpp *.h
	${CXX} ${CXXFLAGS} -c customer.cpp
order.o: order.cpp *.h
	${CXX} ${CXXFLAGS} -c order.cpp
store.o: store.cpp *.h
	${CXX} ${CXXFLAGS} -c store.cpp
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS)
photo:
	gnome-screenshot -i
run:
	./main
clean:
	-rm -f *.gch *.o a.out main
clean2:
	-rm -f *.gch *.o a.out main *.png *.zip
