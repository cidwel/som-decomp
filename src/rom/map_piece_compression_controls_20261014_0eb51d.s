.setcpu "65816"
.segment "CODE"
.org $B51D
map_control_0eb51d:
    .byte $D7 ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
