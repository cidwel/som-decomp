.setcpu "65816"
.segment "CODE"
.org $4A55
map_control_0e4a55:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
