.setcpu "65816"
.segment "CODE"
.org $4654
map_control_0c4654:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
