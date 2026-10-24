.setcpu "65816"
.segment "CODE"
.org $4A7D
map_control_0c4a7d:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
