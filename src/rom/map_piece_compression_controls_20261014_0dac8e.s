.setcpu "65816"
.segment "CODE"
.org $AC8E
map_control_0dac8e:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
