.setcpu "65816"
.segment "CODE"
.org $B7FF
map_control_0db7ff:
    .byte $C1 ; same-value copy count/distance
