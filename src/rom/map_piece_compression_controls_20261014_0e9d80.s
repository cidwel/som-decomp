.setcpu "65816"
.segment "CODE"
.org $9D80
map_control_0e9d80:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
