.setcpu "65816"
.segment "CODE"
.org $146A
map_control_0e146a:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
