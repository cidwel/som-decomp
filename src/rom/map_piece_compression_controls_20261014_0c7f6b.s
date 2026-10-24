.setcpu "65816"
.segment "CODE"
.org $7F6B
map_control_0c7f6b:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
