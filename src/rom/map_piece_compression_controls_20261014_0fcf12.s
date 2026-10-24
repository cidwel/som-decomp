.setcpu "65816"
.segment "CODE"
.org $CF12
map_control_0fcf12:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
