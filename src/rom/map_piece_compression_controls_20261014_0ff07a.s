.setcpu "65816"
.segment "CODE"
.org $F07A
map_control_0ff07a:
    .byte $C4 ; same-value copy count/distance
