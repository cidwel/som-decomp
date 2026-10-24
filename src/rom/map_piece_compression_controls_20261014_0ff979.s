.setcpu "65816"
.segment "CODE"
.org $F979
map_control_0ff979:
    .byte $C2 ; same-value copy count/distance
