.setcpu "65816"
.segment "CODE"
.org $10F0
map_control_0d10f0:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
