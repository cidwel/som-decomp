.setcpu "65816"
.segment "CODE"
.org $4DE3
map_control_0d4de3:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
