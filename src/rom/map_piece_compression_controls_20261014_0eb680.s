.setcpu "65816"
.segment "CODE"
.org $B680
map_control_0eb680:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
