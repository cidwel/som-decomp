.setcpu "65816"
.segment "CODE"
.org $7263
map_control_0d7263:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
