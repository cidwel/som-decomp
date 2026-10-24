.setcpu "65816"
.segment "CODE"
.org $34D9
map_control_0e34d9:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
