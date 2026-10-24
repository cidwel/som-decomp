.setcpu "65816"
.segment "CODE"
.org $BB7E
map_control_0fbb7e:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
