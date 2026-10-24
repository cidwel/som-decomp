.setcpu "65816"
.segment "CODE"
.org $F0C7
map_control_0ff0c7:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
