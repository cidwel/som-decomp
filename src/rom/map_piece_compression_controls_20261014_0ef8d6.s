.setcpu "65816"
.segment "CODE"
.org $F8D6
map_control_0ef8d6:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
