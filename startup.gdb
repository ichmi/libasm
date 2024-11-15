set pagination off
set disassembly-flavor intel

break __loop
run

disassemble __loop
info registers

x/s $rdi
x/s $rsi

x/i $pc