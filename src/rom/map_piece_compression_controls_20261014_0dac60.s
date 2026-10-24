.setcpu "65816"
.segment "CODE"
.org $AC60
map_control_0dac60:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
