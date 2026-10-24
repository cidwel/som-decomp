.setcpu "65816"
.segment "CODE"
.org $D5C0
map_control_0dd5c0:
    .byte $E8 ; backreference distance high bits
    .byte $68 ; distance low bit/count
