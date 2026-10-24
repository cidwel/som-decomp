.setcpu "65816"
.segment "CODE"
.org $EDB8
map_control_0fedb8:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
