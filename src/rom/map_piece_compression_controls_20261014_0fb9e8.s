.setcpu "65816"
.segment "CODE"
.org $B9E8
map_control_0fb9e8:
    .byte $E9 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
