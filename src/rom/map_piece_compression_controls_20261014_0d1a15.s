.setcpu "65816"
.segment "CODE"
.org $1A15
map_control_0d1a15:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
