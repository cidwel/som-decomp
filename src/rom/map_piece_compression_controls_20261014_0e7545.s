.setcpu "65816"
.segment "CODE"
.org $7545
map_control_0e7545:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $09 ; distance low bit/count
