.setcpu "65816"
.segment "CODE"
.org $40BD
map_control_0f40bd:
    .byte $CA ; same-value copy count/distance
