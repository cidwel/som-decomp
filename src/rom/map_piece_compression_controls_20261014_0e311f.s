.setcpu "65816"
.segment "CODE"
.org $311F
map_control_0e311f:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
