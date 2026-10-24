.setcpu "65816"
.segment "CODE"
.org $94F2
map_control_0d94f2:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
