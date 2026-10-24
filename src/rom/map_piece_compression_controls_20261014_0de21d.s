.setcpu "65816"
.segment "CODE"
.org $E21D
map_control_0de21d:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
