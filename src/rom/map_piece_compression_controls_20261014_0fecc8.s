.setcpu "65816"
.segment "CODE"
.org $ECC8
map_control_0fecc8:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
