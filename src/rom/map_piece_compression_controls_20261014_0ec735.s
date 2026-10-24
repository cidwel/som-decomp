.setcpu "65816"
.segment "CODE"
.org $C735
map_control_0ec735:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
