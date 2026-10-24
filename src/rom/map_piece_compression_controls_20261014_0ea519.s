.setcpu "65816"
.segment "CODE"
.org $A519
map_control_0ea519:
    .byte $DA ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
