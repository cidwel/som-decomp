.setcpu "65816"
.segment "CODE"
.org $F31F
map_control_0ef31f:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
