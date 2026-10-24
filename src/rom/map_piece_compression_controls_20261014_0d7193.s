.setcpu "65816"
.segment "CODE"
.org $7193
map_control_0d7193:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
