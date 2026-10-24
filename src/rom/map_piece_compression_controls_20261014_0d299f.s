.setcpu "65816"
.segment "CODE"
.org $299F
map_control_0d299f:
    .byte $D7 ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
