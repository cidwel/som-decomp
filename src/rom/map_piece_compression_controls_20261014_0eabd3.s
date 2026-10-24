.setcpu "65816"
.segment "CODE"
.org $ABD3
map_control_0eabd3:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
