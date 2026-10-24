.setcpu "65816"
.segment "CODE"
.org $85A0
map_control_0d85a0:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
