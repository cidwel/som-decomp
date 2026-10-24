.setcpu "65816"
.segment "CODE"
.org $7066
map_control_0f7066:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
