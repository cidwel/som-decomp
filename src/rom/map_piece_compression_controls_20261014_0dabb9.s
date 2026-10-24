.setcpu "65816"
.segment "CODE"
.org $ABB9
map_control_0dabb9:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
