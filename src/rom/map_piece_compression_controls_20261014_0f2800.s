.setcpu "65816"
.segment "CODE"
.org $2800
map_control_0f2800:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
