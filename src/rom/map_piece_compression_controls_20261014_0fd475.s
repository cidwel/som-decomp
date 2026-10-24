.setcpu "65816"
.segment "CODE"
.org $D475
map_control_0fd475:
    .byte $D7 ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
