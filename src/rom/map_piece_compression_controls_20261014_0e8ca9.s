.setcpu "65816"
.segment "CODE"
.org $8CA9
map_control_0e8ca9:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
