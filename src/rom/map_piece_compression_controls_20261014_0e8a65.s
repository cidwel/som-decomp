.setcpu "65816"
.segment "CODE"
.org $8A65
map_control_0e8a65:
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
