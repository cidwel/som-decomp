.setcpu "65816"
.segment "CODE"
.org $1E19
map_control_0d1e19:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
