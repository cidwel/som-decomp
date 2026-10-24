.setcpu "65816"
.segment "CODE"
.org $B488
map_control_0db488:
    .byte $D5 ; same-value copy count/distance
