.setcpu "65816"
.segment "CODE"
.org $48C8
map_control_0c48c8:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
