.setcpu "65816"
.segment "CODE"
.org $F33B
map_control_0ef33b:
    .byte $E8 ; backreference distance high bits
    .byte $56 ; distance low bit/count
