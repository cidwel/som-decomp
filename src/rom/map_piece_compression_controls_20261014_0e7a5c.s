.setcpu "65816"
.segment "CODE"
.org $7A5C
map_control_0e7a5c:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
