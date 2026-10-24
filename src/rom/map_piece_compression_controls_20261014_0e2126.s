.setcpu "65816"
.segment "CODE"
.org $2126
map_control_0e2126:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
