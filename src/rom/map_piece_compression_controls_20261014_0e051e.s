.setcpu "65816"
.segment "CODE"
.org $051E
map_control_0e051e:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
