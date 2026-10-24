.setcpu "65816"
.segment "CODE"
.org $5998
map_control_0f5998:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
