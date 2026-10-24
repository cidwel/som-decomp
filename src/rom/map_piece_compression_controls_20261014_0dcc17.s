.setcpu "65816"
.segment "CODE"
.org $CC17
map_control_0dcc17:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
