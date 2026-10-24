.setcpu "65816"
.segment "CODE"
.org $B9C4
map_control_0db9c4:
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
