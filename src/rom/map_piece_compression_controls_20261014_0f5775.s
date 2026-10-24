.setcpu "65816"
.segment "CODE"
.org $5775
map_control_0f5775:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
