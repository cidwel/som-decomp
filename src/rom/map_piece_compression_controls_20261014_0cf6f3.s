.setcpu "65816"
.segment "CODE"
.org $F6F3
map_control_0cf6f3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
