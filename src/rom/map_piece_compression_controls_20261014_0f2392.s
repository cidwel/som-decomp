.setcpu "65816"
.segment "CODE"
.org $2392
map_control_0f2392:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
