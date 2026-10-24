.setcpu "65816"
.segment "CODE"
.org $8D31
map_control_0c8d31:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
