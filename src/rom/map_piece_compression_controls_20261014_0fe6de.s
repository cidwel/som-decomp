.setcpu "65816"
.segment "CODE"
.org $E6DE
map_control_0fe6de:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
