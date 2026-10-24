.setcpu "65816"
.segment "CODE"
.org $6C54
map_control_0e6c54:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
