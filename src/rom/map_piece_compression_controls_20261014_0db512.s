.setcpu "65816"
.segment "CODE"
.org $B512
map_control_0db512:
    .byte $C1 ; same-value copy count/distance
