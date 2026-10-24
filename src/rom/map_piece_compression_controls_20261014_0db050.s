.setcpu "65816"
.segment "CODE"
.org $B050
map_control_0db050:
    .byte $C4 ; same-value copy count/distance
