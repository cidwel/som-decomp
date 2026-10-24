.setcpu "65816"
.segment "CODE"
.org $7A40
map_control_0c7a40:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
