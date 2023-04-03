CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g -Werror=vla
EXEC = sorcery
OBJECTS = main.o adaptor.o ascii_graphics.o card.o enchantmentdecorator.o enchantments.o gamecontroller.o graphicaldisplay.o hasability.o minion.o observer.o PRNG.o ritual.o spell.o subject.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

