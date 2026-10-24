.setcpu "65816"
.segment "CODE"
.org $2D4E
map_control_0e2d4e:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
