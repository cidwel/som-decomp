.setcpu "65816"
.segment "CODE"
.org $0CE1
map_control_0f0ce1:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
