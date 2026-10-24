.setcpu "65816"
.segment "CODE"
.org $BEA4
map_control_0ebea4:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count
