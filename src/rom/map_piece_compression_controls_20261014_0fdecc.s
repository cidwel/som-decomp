.setcpu "65816"
.segment "CODE"
.org $DECC
map_control_0fdecc:
    .byte $CA ; same-value copy count/distance
