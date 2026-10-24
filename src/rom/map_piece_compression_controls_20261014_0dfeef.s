.setcpu "65816"
.segment "CODE"
.org $FEEF
map_control_0dfeef:
    .byte $C2 ; same-value copy count/distance
