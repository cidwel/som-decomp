.setcpu "65816"
.segment "CODE"
.org $98E1
map_control_0d98e1:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
