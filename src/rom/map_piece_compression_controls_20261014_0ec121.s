.setcpu "65816"
.segment "CODE"
.org $C121
map_control_0ec121:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
