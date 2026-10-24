.setcpu "65816"
.segment "CODE"
.org $4BEA
map_control_0d4bea:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
