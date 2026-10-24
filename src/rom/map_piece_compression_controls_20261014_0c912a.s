.setcpu "65816"
.segment "CODE"
.org $912A
map_control_0c912a:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
