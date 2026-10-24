.setcpu "65816"
.segment "CODE"
.org $E009
map_control_0fe009:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
