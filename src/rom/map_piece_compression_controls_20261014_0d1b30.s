.setcpu "65816"
.segment "CODE"
.org $1B30
map_control_0d1b30:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
