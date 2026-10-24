.setcpu "65816"
.segment "CODE"
.org $10BD
map_control_0d10bd:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
