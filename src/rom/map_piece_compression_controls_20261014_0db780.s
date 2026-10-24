.setcpu "65816"
.segment "CODE"
.org $B780
map_control_0db780:
    .byte $C9 ; same-value copy count/distance
