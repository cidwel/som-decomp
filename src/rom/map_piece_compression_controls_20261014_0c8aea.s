.setcpu "65816"
.segment "CODE"
.org $8AEA
map_control_0c8aea:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
