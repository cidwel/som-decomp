.setcpu "65816"
.segment "CODE"
.org $F0BB
map_control_0ff0bb:
    .byte $C4 ; same-value copy count/distance
