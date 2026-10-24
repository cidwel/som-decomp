.setcpu "65816"
.segment "CODE"
.org $F2B9
map_control_0cf2b9:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
