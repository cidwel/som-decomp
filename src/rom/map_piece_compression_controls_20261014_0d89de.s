.setcpu "65816"
.segment "CODE"
.org $89DE
map_control_0d89de:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
