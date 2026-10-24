.setcpu "65816"
.segment "CODE"
.org $EDE6
map_control_0fede6:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
