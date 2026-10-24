.setcpu "65816"
.segment "CODE"
.org $4502
map_control_0c4502:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
