.setcpu "65816"
.segment "CODE"
.org $65F0
map_control_0f65f0:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
