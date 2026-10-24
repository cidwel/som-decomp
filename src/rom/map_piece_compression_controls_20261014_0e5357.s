.setcpu "65816"
.segment "CODE"
.org $5357
map_control_0e5357:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
