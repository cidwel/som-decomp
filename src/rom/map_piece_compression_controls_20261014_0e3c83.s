.setcpu "65816"
.segment "CODE"
.org $3C83
map_control_0e3c83:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
