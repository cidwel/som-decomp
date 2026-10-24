.setcpu "65816"
.segment "CODE"
.org $4C07
map_control_0e4c07:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
