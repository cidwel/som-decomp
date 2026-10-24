.setcpu "65816"
.segment "CODE"
.org $FDBC
map_control_0dfdbc:
    .byte $C1 ; same-value copy count/distance
