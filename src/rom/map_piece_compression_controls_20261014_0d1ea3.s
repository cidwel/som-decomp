.setcpu "65816"
.segment "CODE"
.org $1EA3
map_control_0d1ea3:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
