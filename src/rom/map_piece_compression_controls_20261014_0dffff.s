.setcpu "65816"
.segment "CODE"
.org $FFFF
map_control_0dffff:
    .byte $C2 ; same-value copy count/distance
