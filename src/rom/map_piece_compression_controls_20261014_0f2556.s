.setcpu "65816"
.segment "CODE"
.org $2556
map_control_0f2556:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
