.setcpu "65816"
.segment "CODE"
.org $7C05
map_control_0d7c05:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
