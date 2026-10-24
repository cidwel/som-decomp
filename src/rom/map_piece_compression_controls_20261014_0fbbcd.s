.setcpu "65816"
.segment "CODE"
.org $BBCD
map_control_0fbbcd:
    .byte $D1 ; same-value copy count/distance
