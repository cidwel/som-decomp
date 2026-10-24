.setcpu "65816"
.segment "CODE"
.org $E331
map_control_0de331:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
