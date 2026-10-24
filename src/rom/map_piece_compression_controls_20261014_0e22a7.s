.setcpu "65816"
.segment "CODE"
.org $22A7
map_control_0e22a7:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
