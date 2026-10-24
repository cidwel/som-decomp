.setcpu "65816"
.segment "CODE"
.org $9EA1
map_control_0e9ea1:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
