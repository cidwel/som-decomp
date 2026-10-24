.setcpu "65816"
.segment "CODE"
.org $3066
map_control_0e3066:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
