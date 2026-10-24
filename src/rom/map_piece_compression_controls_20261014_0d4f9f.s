.setcpu "65816"
.segment "CODE"
.org $4F9F
map_control_0d4f9f:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
