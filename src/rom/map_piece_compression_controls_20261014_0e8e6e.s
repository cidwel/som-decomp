.setcpu "65816"
.segment "CODE"
.org $8E6E
map_control_0e8e6e:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
