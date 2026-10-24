.setcpu "65816"
.segment "CODE"
.org $48F6
map_control_0c48f6:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
