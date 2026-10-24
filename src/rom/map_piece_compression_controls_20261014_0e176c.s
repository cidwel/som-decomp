.setcpu "65816"
.segment "CODE"
.org $176C
map_control_0e176c:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
