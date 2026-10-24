.setcpu "65816"
.segment "CODE"
.org $F0B5
map_control_0ff0b5:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
