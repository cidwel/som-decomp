.setcpu "65816"
.segment "CODE"
.org $C6DE
map_control_0ec6de:
    .byte $E8 ; backreference distance high bits
    .byte $9F ; distance low bit/count
