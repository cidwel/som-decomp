.setcpu "65816"
.segment "CODE"
.org $4F0D
map_control_0d4f0d:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
