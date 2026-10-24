.setcpu "65816"
.segment "CODE"
.org $20E2
map_control_0d20e2:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
