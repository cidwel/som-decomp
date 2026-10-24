.setcpu "65816"
.segment "CODE"
.org $4B0A
map_control_0e4b0a:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
