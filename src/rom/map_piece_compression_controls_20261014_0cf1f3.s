.setcpu "65816"
.segment "CODE"
.org $F1F3
map_control_0cf1f3:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
