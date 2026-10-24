; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-text-tick.md.
.setcpu "65816"
.smart
.a8
.i16

divide_menu_number_using_snes_arithmetic_registers = $D0D7E2

.segment "CODE"
.org $D7F9
divide_and_append_native_menu_digit:
    jsl f:divide_menu_number_using_snes_arithmetic_registers
