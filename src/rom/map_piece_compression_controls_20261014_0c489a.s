.setcpu "65816"
.segment "CODE"
.org $489A
map_control_0c489a:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
