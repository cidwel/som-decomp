.setcpu "65816"
.segment "CODE"
.org $2DA6
map_control_0e2da6:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
