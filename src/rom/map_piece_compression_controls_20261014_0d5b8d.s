.setcpu "65816"
.segment "CODE"
.org $5B8D
map_control_0d5b8d:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
