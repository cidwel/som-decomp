.setcpu "65816"
.segment "CODE"
.org $F6D7
map_control_0cf6d7:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
