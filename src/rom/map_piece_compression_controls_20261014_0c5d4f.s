.setcpu "65816"
.segment "CODE"
.org $5D4F
map_control_0c5d4f:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
