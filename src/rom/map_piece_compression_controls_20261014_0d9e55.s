.setcpu "65816"
.segment "CODE"
.org $9E55
map_control_0d9e55:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
