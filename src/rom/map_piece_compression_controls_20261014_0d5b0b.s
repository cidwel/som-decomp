.setcpu "65816"
.segment "CODE"
.org $5B0B
map_control_0d5b0b:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
