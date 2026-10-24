.setcpu "65816"
.segment "CODE"
.org $7666
map_control_0f7666:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
