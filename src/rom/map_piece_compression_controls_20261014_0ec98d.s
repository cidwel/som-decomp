.setcpu "65816"
.segment "CODE"
.org $C98D
map_control_0ec98d:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
