.setcpu "65816"
.segment "CODE"
.org $3685
map_control_0e3685:
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
