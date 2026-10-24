.setcpu "65816"
.segment "CODE"
.org $10CF
map_control_0d10cf:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
