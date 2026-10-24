.setcpu "65816"
.segment "CODE"
.org $8CD1
map_control_0d8cd1:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
