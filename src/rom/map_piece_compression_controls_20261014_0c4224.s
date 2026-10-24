.setcpu "65816"
.segment "CODE"
.org $4224
map_control_0c4224:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
