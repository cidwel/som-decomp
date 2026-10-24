.setcpu "65816"
.segment "CODE"
.org $9B4A
map_control_0e9b4a:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
