.setcpu "65816"
.segment "CODE"
.org $F01F
map_control_0df01f:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
