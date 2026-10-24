.setcpu "65816"
.segment "CODE"
.org $F3F7
map_control_0ff3f7:
    .byte $C2 ; same-value copy count/distance
