.setcpu "65816"
.segment "CODE"
.org $5234
map_control_0e5234:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
