.setcpu "65816"
.segment "CODE"
.org $5B7F
map_control_0e5b7f:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
