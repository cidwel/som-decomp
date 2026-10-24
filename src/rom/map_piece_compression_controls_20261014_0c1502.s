.setcpu "65816"
.segment "CODE"
.org $1502
map_control_0c1502:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
