.setcpu "65816"
.segment "CODE"
.org $6F4F
map_control_0d6f4f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
