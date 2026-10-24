.setcpu "65816"
.segment "CODE"
.org $30BB
map_control_0f30bb:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
