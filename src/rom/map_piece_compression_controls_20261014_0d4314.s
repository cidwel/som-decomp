.setcpu "65816"
.segment "CODE"
.org $4314
map_control_0d4314:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
