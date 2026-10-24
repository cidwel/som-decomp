.setcpu "65816"
.segment "CODE"
.org $CBB9
map_control_0fcbb9:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
