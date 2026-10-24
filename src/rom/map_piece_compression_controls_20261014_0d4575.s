.setcpu "65816"
.segment "CODE"
.org $4575
map_control_0d4575:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
