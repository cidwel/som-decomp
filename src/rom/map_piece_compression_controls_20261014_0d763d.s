.setcpu "65816"
.segment "CODE"
.org $763D
map_control_0d763d:
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
