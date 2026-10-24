.setcpu "65816"
.segment "CODE"
.org $9E9B
map_control_0d9e9b:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
