.setcpu "65816"
.segment "CODE"
.org $8D5D
map_control_0c8d5d:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
