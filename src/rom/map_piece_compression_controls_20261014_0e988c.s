.setcpu "65816"
.segment "CODE"
.org $988C
map_control_0e988c:
    .byte $E8 ; backreference distance high bits
    .byte $98 ; distance low bit/count
