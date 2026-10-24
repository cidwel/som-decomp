.setcpu "65816"
.segment "CODE"
.org $8C77
map_control_0d8c77:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
