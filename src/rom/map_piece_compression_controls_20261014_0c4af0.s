.setcpu "65816"
.segment "CODE"
.org $4AF0
map_control_0c4af0:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
