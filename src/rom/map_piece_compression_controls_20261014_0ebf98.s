.setcpu "65816"
.segment "CODE"
.org $BF98
map_control_0ebf98:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
