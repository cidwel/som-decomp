.setcpu "65816"
.segment "CODE"
.org $3C79
map_control_0e3c79:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
