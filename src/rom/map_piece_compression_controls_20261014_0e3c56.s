.setcpu "65816"
.segment "CODE"
.org $3C56
map_control_0e3c56:
    .byte $F1 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
