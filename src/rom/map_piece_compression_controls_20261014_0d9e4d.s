.setcpu "65816"
.segment "CODE"
.org $9E4D
map_control_0d9e4d:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
