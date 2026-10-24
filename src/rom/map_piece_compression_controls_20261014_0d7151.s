.setcpu "65816"
.segment "CODE"
.org $7151
map_control_0d7151:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
