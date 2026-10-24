.setcpu "65816"
.segment "CODE"
.org $AC11
map_control_0dac11:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
