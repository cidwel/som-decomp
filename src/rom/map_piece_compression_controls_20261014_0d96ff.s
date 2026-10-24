.setcpu "65816"
.segment "CODE"
.org $96FF
map_control_0d96ff:
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
