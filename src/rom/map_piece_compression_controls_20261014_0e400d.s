.setcpu "65816"
.segment "CODE"
.org $400D
map_control_0e400d:
    .byte $F1 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
