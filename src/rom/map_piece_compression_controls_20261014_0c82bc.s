.setcpu "65816"
.segment "CODE"
.org $82BC
map_control_0c82bc:
    .byte $EC ; backreference distance high bits
    .byte $9A ; distance low bit/count
