.setcpu "65816"
.segment "CODE"
.org $F492
map_control_0ef492:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $31 ; distance low bit/count
