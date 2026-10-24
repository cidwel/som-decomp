.setcpu "65816"
.segment "CODE"
.org $DC1B
map_control_0fdc1b:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
