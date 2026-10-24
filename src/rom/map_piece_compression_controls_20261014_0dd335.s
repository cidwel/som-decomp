.setcpu "65816"
.segment "CODE"
.org $D335
map_control_0dd335:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
