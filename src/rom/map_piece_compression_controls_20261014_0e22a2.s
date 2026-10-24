.setcpu "65816"
.segment "CODE"
.org $22A2
map_control_0e22a2:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
