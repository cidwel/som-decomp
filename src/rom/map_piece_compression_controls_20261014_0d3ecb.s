.setcpu "65816"
.segment "CODE"
.org $3ECB
map_control_0d3ecb:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
