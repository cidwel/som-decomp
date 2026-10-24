.setcpu "65816"
.segment "CODE"
.org $54F9
map_control_0c54f9:
    .byte $E9 ; backreference distance high bits
    .byte $8D ; distance low bit/count
