.setcpu "65816"
.segment "CODE"
.org $FF52
map_control_0dff52:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
