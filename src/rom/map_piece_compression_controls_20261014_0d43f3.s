.setcpu "65816"
.segment "CODE"
.org $43F3
map_control_0d43f3:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
