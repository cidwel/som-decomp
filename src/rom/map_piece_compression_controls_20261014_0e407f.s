.setcpu "65816"
.segment "CODE"
.org $407F
map_control_0e407f:
    .byte $EF ; backreference distance high bits
    .byte $0A ; distance low bit/count
