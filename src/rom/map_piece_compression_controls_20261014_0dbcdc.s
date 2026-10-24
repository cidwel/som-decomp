.setcpu "65816"
.segment "CODE"
.org $BCDC
map_control_0dbcdc:
    .byte $C2 ; same-value copy count/distance
