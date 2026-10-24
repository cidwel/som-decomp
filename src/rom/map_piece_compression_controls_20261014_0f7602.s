.setcpu "65816"
.segment "CODE"
.org $7602
map_control_0f7602:
    .byte $EE ; backreference distance high bits
    .byte $07 ; distance low bit/count
