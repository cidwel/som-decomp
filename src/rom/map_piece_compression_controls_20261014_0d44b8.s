.setcpu "65816"
.segment "CODE"
.org $44B8
map_control_0d44b8:
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count
