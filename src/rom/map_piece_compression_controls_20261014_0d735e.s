.setcpu "65816"
.segment "CODE"
.org $735E
map_control_0d735e:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
