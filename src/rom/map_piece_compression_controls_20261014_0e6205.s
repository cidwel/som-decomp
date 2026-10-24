.setcpu "65816"
.segment "CODE"
.org $6205
map_control_0e6205:
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
