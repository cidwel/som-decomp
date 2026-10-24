.setcpu "65816"
.segment "CODE"
.org $3B42
map_control_0f3b42:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
