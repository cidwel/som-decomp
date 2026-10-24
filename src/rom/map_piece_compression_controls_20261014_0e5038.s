.setcpu "65816"
.segment "CODE"
.org $5038
map_control_0e5038:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
