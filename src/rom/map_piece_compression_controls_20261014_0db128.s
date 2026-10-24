.setcpu "65816"
.segment "CODE"
.org $B128
map_control_0db128:
    .byte $CA ; same-value copy count/distance
