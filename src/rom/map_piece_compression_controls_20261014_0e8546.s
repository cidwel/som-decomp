.setcpu "65816"
.segment "CODE"
.org $8546
map_control_0e8546:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
