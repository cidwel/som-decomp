.setcpu "65816"
.segment "CODE"
.org $D6E1
map_control_0dd6e1:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
