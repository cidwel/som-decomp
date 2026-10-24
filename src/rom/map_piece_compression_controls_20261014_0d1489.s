.setcpu "65816"
.segment "CODE"
.org $1489
map_control_0d1489:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
