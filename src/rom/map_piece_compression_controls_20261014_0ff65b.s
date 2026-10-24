.setcpu "65816"
.segment "CODE"
.org $F65B
map_control_0ff65b:
    .byte $C3 ; same-value copy count/distance
