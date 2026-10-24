.setcpu "65816"
.segment "CODE"
.org $07AC
map_control_0f07ac:
    .byte $D6 ; same-value copy count/distance
