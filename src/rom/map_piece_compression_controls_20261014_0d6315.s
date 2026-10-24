.setcpu "65816"
.segment "CODE"
.org $6315
map_control_0d6315:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
