.setcpu "65816"
.segment "CODE"
.org $D332
map_control_0dd332:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
