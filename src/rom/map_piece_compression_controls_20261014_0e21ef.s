.setcpu "65816"
.segment "CODE"
.org $21EF
map_control_0e21ef:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
