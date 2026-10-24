.setcpu "65816"
.segment "CODE"
.org $FEDC
map_control_0dfedc:
    .byte $C9 ; same-value copy count/distance
