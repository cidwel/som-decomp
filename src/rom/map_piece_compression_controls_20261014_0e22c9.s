.setcpu "65816"
.segment "CODE"
.org $22C9
map_control_0e22c9:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
