.setcpu "65816"
.segment "CODE"
.org $AC6F
map_control_0dac6f:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
