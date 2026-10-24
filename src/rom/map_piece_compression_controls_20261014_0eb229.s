.setcpu "65816"
.segment "CODE"
.org $B229
map_control_0eb229:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
