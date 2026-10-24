.setcpu "65816"
.segment "CODE"
.org $BECD
map_control_0dbecd:
    .byte $D4 ; same-value copy count/distance
