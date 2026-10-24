.setcpu "65816"
.segment "CODE"
.org $AC9D
map_control_0dac9d:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
