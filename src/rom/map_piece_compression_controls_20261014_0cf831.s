.setcpu "65816"
.segment "CODE"
.org $F831
map_control_0cf831:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
