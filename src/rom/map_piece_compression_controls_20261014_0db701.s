.setcpu "65816"
.segment "CODE"
.org $B701
map_control_0db701:
    .byte $C6 ; same-value copy count/distance
