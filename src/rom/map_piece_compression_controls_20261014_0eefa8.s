.setcpu "65816"
.segment "CODE"
.org $EFA8
map_control_0eefa8:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
