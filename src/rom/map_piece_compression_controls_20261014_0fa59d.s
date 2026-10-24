.setcpu "65816"
.segment "CODE"
.org $A59D
map_control_0fa59d:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
