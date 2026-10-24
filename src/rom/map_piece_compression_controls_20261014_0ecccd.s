.setcpu "65816"
.segment "CODE"
.org $CCCD
map_control_0ecccd:
    .byte $C7 ; same-value copy count/distance
