.setcpu "65816"
.segment "CODE"
.org $FA7E
map_control_0efa7e:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
