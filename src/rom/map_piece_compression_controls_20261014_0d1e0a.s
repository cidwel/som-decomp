.setcpu "65816"
.segment "CODE"
.org $1E0A
map_control_0d1e0a:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
