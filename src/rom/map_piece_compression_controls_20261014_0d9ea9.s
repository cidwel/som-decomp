.setcpu "65816"
.segment "CODE"
.org $9EA9
map_control_0d9ea9:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
