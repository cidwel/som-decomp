.setcpu "65816"
.segment "CODE"
.org $4550
map_control_0c4550:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
