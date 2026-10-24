.setcpu "65816"
.segment "CODE"
.org $7172
map_control_0d7172:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
