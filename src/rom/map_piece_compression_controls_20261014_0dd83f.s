.setcpu "65816"
.segment "CODE"
.org $D83F
map_control_0dd83f:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
