.setcpu "65816"
.segment "CODE"
.org $F68A
map_control_0cf68a:
    .byte $EC ; backreference distance high bits
    .byte $03 ; distance low bit/count
