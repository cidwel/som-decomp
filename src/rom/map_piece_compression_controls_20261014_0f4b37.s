.setcpu "65816"
.segment "CODE"
.org $4B37
map_control_0f4b37:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
