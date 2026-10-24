.setcpu "65816"
.segment "CODE"
.org $232E
map_control_0e232e:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
