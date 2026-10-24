.setcpu "65816"
.segment "CODE"
.org $5BA5
map_control_0d5ba5:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
