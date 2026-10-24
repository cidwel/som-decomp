.setcpu "65816"
.segment "CODE"
.org $0BF8
map_control_0d0bf8:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
