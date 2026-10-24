.setcpu "65816"
.segment "CODE"
.org $1813
map_control_0e1813:
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
