.setcpu "65816"
.segment "CODE"
.org $AC3B
map_control_0dac3b:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
