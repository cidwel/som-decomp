.setcpu "65816"
.segment "CODE"
.org $1F97
map_control_0d1f97:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
