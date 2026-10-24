.setcpu "65816"
.segment "CODE"
.org $FADC
map_control_0dfadc:
    .byte $C1 ; same-value copy count/distance
