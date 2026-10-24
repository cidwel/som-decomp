.setcpu "65816"
.segment "CODE"
.org $6738
map_control_0d6738:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
