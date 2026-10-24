.setcpu "65816"
.segment "CODE"
.org $6313
map_control_0c6313:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
