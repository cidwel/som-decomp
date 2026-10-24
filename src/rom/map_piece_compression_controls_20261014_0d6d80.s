.setcpu "65816"
.segment "CODE"
.org $6D80
map_control_0d6d80:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
