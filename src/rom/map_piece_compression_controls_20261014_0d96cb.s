.setcpu "65816"
.segment "CODE"
.org $96CB
map_control_0d96cb:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
