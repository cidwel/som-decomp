.setcpu "65816"
.segment "CODE"
.org $9265
map_control_0c9265:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
