.setcpu "65816"
.segment "CODE"
.org $FFBB
map_control_0dffbb:
    .byte $C1 ; same-value copy count/distance
