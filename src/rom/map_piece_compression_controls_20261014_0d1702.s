.setcpu "65816"
.segment "CODE"
.org $1702
map_control_0d1702:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
