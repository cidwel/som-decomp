.setcpu "65816"
.segment "CODE"
.org $293F
map_control_0e293f:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
