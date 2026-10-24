.setcpu "65816"
.segment "CODE"
.org $2F4F
map_control_0f2f4f:
    .byte $E8 ; backreference distance high bits
    .byte $8F ; distance low bit/count
