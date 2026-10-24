.setcpu "65816"
.segment "CODE"
.org $4486
map_control_0d4486:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
