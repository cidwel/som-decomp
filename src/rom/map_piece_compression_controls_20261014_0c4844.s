.setcpu "65816"
.segment "CODE"
.org $4844
map_control_0c4844:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
