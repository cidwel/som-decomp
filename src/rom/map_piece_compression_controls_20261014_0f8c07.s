.setcpu "65816"
.segment "CODE"
.org $8C07
map_control_0f8c07:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
