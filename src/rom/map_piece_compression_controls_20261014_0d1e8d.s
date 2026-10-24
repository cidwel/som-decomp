.setcpu "65816"
.segment "CODE"
.org $1E8D
map_control_0d1e8d:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
