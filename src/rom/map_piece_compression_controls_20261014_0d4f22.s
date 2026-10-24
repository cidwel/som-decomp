.setcpu "65816"
.segment "CODE"
.org $4F22
map_control_0d4f22:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
