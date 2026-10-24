.setcpu "65816"
.segment "CODE"
.org $0A7D
map_control_0d0a7d:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
