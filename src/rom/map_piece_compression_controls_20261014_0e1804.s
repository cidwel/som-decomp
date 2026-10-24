.setcpu "65816"
.segment "CODE"
.org $1804
map_control_0e1804:
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
