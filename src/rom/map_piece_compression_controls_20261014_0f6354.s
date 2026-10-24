.setcpu "65816"
.segment "CODE"
.org $6354
map_control_0f6354:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
