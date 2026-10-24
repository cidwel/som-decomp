.setcpu "65816"
.segment "CODE"
.org $2D90
map_control_0e2d90:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
