.setcpu "65816"
.segment "CODE"
.org $871E
map_control_0e871e:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
