.setcpu "65816"
.segment "CODE"
.org $F03A
map_control_0ff03a:
    .byte $C4 ; same-value copy count/distance
