.setcpu "65816"
.segment "CODE"
.org $8051
map_control_0e8051:
    .byte $C1 ; same-value copy count/distance
