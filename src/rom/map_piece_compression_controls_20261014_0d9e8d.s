.setcpu "65816"
.segment "CODE"
.org $9E8D
map_control_0d9e8d:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
