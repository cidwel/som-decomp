.setcpu "65816"
.segment "CODE"
.org $8C74
map_control_0d8c74:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
