.setcpu "65816"
.segment "CODE"
.org $7D10
map_control_0e7d10:
    .byte $EC ; backreference distance high bits
    .byte $07 ; distance low bit/count
