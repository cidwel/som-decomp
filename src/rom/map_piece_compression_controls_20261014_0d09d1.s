.setcpu "65816"
.segment "CODE"
.org $09D1
map_control_0d09d1:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
