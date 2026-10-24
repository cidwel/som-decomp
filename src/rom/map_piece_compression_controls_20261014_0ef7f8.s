.setcpu "65816"
.segment "CODE"
.org $F7F8
map_control_0ef7f8:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
