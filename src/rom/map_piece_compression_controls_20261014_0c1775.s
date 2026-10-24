.setcpu "65816"
.segment "CODE"
.org $1775
map_control_0c1775:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
