.setcpu "65816"
.segment "CODE"
.org $8E03
map_control_0f8e03:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
