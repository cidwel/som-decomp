.setcpu "65816"
.segment "CODE"
.org $BA0B
map_control_0dba0b:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
