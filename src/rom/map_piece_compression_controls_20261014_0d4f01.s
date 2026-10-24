.setcpu "65816"
.segment "CODE"
.org $4F01
map_control_0d4f01:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
