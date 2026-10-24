.setcpu "65816"
.segment "CODE"
.org $D6A8
map_control_0dd6a8:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
