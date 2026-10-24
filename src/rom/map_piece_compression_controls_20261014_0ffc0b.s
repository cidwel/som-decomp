.setcpu "65816"
.segment "CODE"
.org $FC0B
map_control_0ffc0b:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
