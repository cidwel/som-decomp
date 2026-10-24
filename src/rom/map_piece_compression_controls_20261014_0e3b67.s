.setcpu "65816"
.segment "CODE"
.org $3B67
map_control_0e3b67:
    .byte $F1 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
