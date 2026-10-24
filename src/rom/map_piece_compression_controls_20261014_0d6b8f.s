.setcpu "65816"
.segment "CODE"
.org $6B8F
map_control_0d6b8f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
