.setcpu "65816"
.segment "CODE"
.org $9184
map_control_0c9184:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
