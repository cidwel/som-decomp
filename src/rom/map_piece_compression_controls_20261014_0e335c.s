.setcpu "65816"
.segment "CODE"
.org $335C
map_control_0e335c:
    .byte $EA ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
