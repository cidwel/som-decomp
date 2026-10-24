.setcpu "65816"
.segment "CODE"
.org $AC7E
map_control_0dac7e:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
