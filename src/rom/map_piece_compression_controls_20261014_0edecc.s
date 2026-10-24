.setcpu "65816"
.segment "CODE"
.org $DECC
map_control_0edecc:
    .byte $C1 ; same-value copy count/distance
