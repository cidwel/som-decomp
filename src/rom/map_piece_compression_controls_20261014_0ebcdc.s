.setcpu "65816"
.segment "CODE"
.org $BCDC
map_control_0ebcdc:
    .byte $D1 ; same-value copy count/distance
