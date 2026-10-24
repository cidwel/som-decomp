.setcpu "65816"
.segment "CODE"
.org $FEFD
map_control_0dfefd:
    .byte $C2 ; same-value copy count/distance
