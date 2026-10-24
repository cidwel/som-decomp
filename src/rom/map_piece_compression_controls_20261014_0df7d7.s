.setcpu "65816"
.segment "CODE"
.org $F7D7
map_control_0df7d7:
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
