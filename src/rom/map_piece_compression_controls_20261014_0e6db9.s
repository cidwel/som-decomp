.setcpu "65816"
.segment "CODE"
.org $6DB9
map_control_0e6db9:
    .byte $E8 ; backreference distance high bits
    .byte $7E ; distance low bit/count
