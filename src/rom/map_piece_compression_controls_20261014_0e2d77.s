.setcpu "65816"
.segment "CODE"
.org $2D77
map_control_0e2d77:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
