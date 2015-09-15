objs := start.o lowlevel_init.o  main.o 

boot.bin: $(objs)
	arm-linux-ld -Map boot.map -Tboot.lds -o boot_elf $^
	arm-linux-objcopy -O binary -S boot_elf $@
	
%.o:%.c
	arm-linux-gcc -Wall  -c -o $@ $<

%.o:%.S
	arm-linux-gcc -Wall  -c -o $@ $<

clean:
	rm -f *elf *.o	
