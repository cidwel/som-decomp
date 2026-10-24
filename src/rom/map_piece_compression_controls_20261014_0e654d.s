.setcpu "65816"
.segment "CODE"
.org $654D
map_control_0e654d:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
