.setcpu "65816"
.segment "CODE"
.org $1D89
map_control_0d1d89:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
