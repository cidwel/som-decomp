.setcpu "65816"
.segment "CODE"
.org $ED3F
map_control_0ded3f:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
