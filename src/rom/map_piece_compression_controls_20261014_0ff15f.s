.setcpu "65816"
.segment "CODE"
.org $F15F
map_control_0ff15f:
    .byte $EB ; backreference distance high bits
    .byte $8D ; distance low bit/count
