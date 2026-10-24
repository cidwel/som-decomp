.setcpu "65816"
.segment "CODE"
.org $AB8D
map_control_0dab8d:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
