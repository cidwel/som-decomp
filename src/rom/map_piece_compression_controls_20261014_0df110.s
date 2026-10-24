.setcpu "65816"
.segment "CODE"
.org $F110
map_control_0df110:
    .byte $C4 ; same-value copy count/distance
