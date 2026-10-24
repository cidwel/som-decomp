.setcpu "65816"
.segment "CODE"
.org $F3AC
map_control_0cf3ac:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
