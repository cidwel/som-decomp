.setcpu "65816"
.segment "CODE"
.org $BDDC
map_control_0dbddc:
    .byte $C1 ; same-value copy count/distance
