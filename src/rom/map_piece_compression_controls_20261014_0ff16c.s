.setcpu "65816"
.segment "CODE"
.org $F16C
map_control_0ff16c:
    .byte $C4 ; same-value copy count/distance
