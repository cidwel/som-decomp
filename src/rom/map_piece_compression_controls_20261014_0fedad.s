.setcpu "65816"
.segment "CODE"
.org $EDAD
map_control_0fedad:
    .byte $C3 ; same-value copy count/distance
