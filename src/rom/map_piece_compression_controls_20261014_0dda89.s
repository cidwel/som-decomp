.setcpu "65816"
.segment "CODE"
.org $DA89
map_control_0dda89:
    .byte $E8 ; backreference distance high bits
    .byte $76 ; distance low bit/count
