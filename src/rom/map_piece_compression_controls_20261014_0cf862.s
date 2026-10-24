.setcpu "65816"
.segment "CODE"
.org $F862
map_control_0cf862:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
