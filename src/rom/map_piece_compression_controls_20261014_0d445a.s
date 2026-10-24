.setcpu "65816"
.segment "CODE"
.org $445A
map_control_0d445a:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
