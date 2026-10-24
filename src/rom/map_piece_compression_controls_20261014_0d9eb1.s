.setcpu "65816"
.segment "CODE"
.org $9EB1
map_control_0d9eb1:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
