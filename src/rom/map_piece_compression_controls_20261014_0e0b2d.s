.setcpu "65816"
.segment "CODE"
.org $0B2D
map_control_0e0b2d:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
