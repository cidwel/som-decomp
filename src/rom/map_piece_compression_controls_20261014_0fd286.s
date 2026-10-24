.setcpu "65816"
.segment "CODE"
.org $D286
map_control_0fd286:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
