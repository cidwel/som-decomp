.setcpu "65816"
.segment "CODE"
.org $30B2
map_control_0e30b2:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
