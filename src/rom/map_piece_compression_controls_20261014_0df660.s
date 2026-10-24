.setcpu "65816"
.segment "CODE"
.org $F660
map_control_0df660:
    .byte $D7 ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
