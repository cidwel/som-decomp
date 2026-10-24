.setcpu "65816"
.segment "CODE"
.org $FDDC
map_control_0dfddc:
    .byte $C1 ; same-value copy count/distance
