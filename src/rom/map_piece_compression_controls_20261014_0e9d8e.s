.setcpu "65816"
.segment "CODE"
.org $9D8E
map_control_0e9d8e:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
