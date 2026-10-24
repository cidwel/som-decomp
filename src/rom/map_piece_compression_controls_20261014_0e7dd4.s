.setcpu "65816"
.segment "CODE"
.org $7DD4
map_control_0e7dd4:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
