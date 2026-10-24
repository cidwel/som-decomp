.setcpu "65816"
.segment "CODE"
.org $DF33
map_control_0fdf33:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
