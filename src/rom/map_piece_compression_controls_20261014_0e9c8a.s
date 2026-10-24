.setcpu "65816"
.segment "CODE"
.org $9C8A
map_control_0e9c8a:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
