.setcpu "65816"
.segment "CODE"
.org $B440
map_control_0db440:
    .byte $C2 ; same-value copy count/distance
