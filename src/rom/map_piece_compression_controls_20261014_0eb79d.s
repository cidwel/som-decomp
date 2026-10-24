.setcpu "65816"
.segment "CODE"
.org $B79D
map_control_0eb79d:
    .byte $E8 ; backreference distance high bits
    .byte $67 ; distance low bit/count
