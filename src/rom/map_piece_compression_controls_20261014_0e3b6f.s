.setcpu "65816"
.segment "CODE"
.org $3B6F
map_control_0e3b6f:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
