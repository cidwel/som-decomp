.setcpu "65816"
.segment "CODE"
.org $07A0
map_control_0f07a0:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
