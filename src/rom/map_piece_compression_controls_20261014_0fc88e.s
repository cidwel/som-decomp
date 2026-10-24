.setcpu "65816"
.segment "CODE"
.org $C88E
map_control_0fc88e:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
