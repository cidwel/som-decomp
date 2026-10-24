.setcpu "65816"
.segment "CODE"
.org $1737
map_control_0e1737:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
