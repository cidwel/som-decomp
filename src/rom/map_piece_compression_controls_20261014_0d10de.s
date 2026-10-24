.setcpu "65816"
.segment "CODE"
.org $10DE
map_control_0d10de:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
