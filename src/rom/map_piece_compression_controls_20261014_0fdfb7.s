.setcpu "65816"
.segment "CODE"
.org $DFB7
map_control_0fdfb7:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
