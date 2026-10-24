.setcpu "65816"
.segment "CODE"
.org $1BAD
map_control_0e1bad:
    .byte $C2 ; same-value copy count/distance
