.setcpu "65816"
.segment "CODE"
.org $6B55
map_control_0c6b55:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
