.setcpu "65816"
.segment "CODE"
.org $76D6
map_control_0f76d6:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
