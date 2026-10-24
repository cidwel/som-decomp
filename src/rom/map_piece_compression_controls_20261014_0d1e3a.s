.setcpu "65816"
.segment "CODE"
.org $1E3A
map_control_0d1e3a:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
