.setcpu "65816"
.segment "CODE"
.org $4DE3
map_control_0c4de3:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
