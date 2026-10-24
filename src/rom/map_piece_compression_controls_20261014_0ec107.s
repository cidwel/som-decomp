.setcpu "65816"
.segment "CODE"
.org $C107
map_control_0ec107:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
