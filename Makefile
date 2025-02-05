all: o2ss2o o2s s2o

o2ss2o: o2ss2o.c
	gcc $^ -o $@

o2s: o2ss2o
	ln -s $^ $@

s2o: o2ss2o
	ln -s $^ $@
clean:
	rm -f o2ss2o o2s s2o *.o
