.setcpu "65816"
.segment "CODE"
.org $1E24
map_control_0d1e24:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
