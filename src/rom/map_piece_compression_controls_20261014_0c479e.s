.setcpu "65816"
.segment "CODE"
.org $479E
map_control_0c479e:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
