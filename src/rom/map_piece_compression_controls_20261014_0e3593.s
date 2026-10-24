.setcpu "65816"
.segment "CODE"
.org $3593
map_control_0e3593:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
