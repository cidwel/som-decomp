.setcpu "65816"
.segment "CODE"
.org $F1C6
map_control_0ff1c6:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
