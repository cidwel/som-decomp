.setcpu "65816"
.segment "CODE"
.org $451D
map_control_0c451d:
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
