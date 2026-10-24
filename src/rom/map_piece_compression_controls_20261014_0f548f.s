.setcpu "65816"
.segment "CODE"
.org $548F
map_control_0f548f:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
