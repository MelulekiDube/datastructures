#Make file adapted from https://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/
#


CC := gcc 
# CC := clang --analyze # and comment out the linker last line for sanity
LLDIR := linkedlists
SPIKESDIR := spikes
ll:
	make -C $(LLDIR)

spike:
	make -C $(SPIKESDIR)
	
runsp:
	make run -C $(SPIKESDIR)
	
runll:
	make run -C $(LLDIR)
clean:
	make clean -C $(LLDIR)
	make clean -C $(SPIKESDIR)

.PHONY: clean