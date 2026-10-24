.setcpu "65816"
.segment "CODE"
.org $30D7
map_control_0f30d7:
    .byte $E8 ; backreference distance high bits
    .byte $C1 ; distance low bit/count
