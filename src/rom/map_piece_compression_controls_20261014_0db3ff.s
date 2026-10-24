.setcpu "65816"
.segment "CODE"
.org $B3FF
map_control_0db3ff:
    .byte $CE ; same-value copy count/distance
