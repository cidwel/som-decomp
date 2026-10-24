.setcpu "65816"
.segment "CODE"
.org $4CC0
map_control_0d4cc0:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
