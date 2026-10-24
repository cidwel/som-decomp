.setcpu "65816"
.segment "CODE"
.org $30AD
map_control_0e30ad:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
