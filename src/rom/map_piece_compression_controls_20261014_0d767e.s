.setcpu "65816"
.segment "CODE"
.org $767E
map_control_0d767e:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
