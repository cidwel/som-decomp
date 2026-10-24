.setcpu "65816"
.segment "CODE"
.org $1E78
map_control_0d1e78:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
