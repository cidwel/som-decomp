.setcpu "65816"
.segment "CODE"
.org $9D80
map_control_0d9d80:
    .byte $E8 ; backreference distance high bits
    .byte $96 ; distance low bit/count
