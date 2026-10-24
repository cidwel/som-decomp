.setcpu "65816"
.segment "CODE"
.org $F114
map_control_0df114:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
