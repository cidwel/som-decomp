.setcpu "65816"
.segment "CODE"
.org $B00A
map_control_0db00a:
    .byte $C1 ; same-value copy count/distance
