.setcpu "65816"
.segment "CODE"
.org $D3A2
map_control_0dd3a2:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
