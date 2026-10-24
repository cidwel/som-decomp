.setcpu "65816"
.segment "CODE"
.org $56F6
map_control_0c56f6:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
