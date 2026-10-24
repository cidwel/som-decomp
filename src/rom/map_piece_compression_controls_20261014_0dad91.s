.setcpu "65816"
.segment "CODE"
.org $AD91
map_control_0dad91:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
