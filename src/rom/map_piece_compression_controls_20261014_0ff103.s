.setcpu "65816"
.segment "CODE"
.org $F103
map_control_0ff103:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
