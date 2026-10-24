.setcpu "65816"
.segment "CODE"
.org $AC1A
map_control_0dac1a:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
