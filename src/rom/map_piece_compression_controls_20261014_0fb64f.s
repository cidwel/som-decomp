.setcpu "65816"
.segment "CODE"
.org $B64F
map_control_0fb64f:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
