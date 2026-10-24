.setcpu "65816"
.segment "CODE"
.org $FB0E
map_control_0cfb0e:
    .byte $D7 ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
