.setcpu "65816"
.segment "CODE"
.org $CBD9
map_control_0fcbd9:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
