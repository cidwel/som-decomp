.setcpu "65816"
.segment "CODE"
.org $6E0F
map_control_0d6e0f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
