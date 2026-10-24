.setcpu "65816"
.segment "CODE"
.org $6E17
map_control_0d6e17:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
