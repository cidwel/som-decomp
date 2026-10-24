.setcpu "65816"
.segment "CODE"
.org $8106
map_control_0f8106:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
