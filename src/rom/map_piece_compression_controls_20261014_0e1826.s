.setcpu "65816"
.segment "CODE"
.org $1826
map_control_0e1826:
    .byte $EB ; backreference distance high bits
    .byte $09 ; distance low bit/count
