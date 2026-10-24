.setcpu "65816"
.segment "CODE"
.org $9EB9
map_control_0d9eb9:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
