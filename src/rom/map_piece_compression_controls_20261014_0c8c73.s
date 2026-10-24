.setcpu "65816"
.segment "CODE"
.org $8C73
map_control_0c8c73:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
