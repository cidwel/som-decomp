.setcpu "65816"
.segment "CODE"
.org $D0A0
map_control_0ed0a0:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
