.setcpu "65816"
.segment "CODE"
.org $35B4
map_control_0e35b4:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
