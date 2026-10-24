.setcpu "65816"
.segment "CODE"
.org $EE00
map_control_0fee00:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
