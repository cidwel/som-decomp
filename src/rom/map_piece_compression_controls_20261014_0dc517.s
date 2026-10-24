.setcpu "65816"
.segment "CODE"
.org $C517
map_control_0dc517:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
