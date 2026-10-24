.setcpu "65816"
.segment "CODE"
.org $6E0D
map_control_0e6e0d:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
