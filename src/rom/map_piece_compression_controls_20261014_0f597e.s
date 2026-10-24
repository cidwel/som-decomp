.setcpu "65816"
.segment "CODE"
.org $597E
map_control_0f597e:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
