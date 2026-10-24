.setcpu "65816"
.segment "CODE"
.org $917E
map_control_0c917e:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
