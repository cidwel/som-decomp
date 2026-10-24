.setcpu "65816"
.segment "CODE"
.org $9C74
map_control_0e9c74:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count
