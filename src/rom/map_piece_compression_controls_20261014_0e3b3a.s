.setcpu "65816"
.segment "CODE"
.org $3B3A
map_control_0e3b3a:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
