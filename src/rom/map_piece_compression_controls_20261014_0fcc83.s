.setcpu "65816"
.segment "CODE"
.org $CC83
map_control_0fcc83:
    .byte $D7 ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
