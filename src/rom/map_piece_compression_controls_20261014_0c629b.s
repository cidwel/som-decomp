.setcpu "65816"
.segment "CODE"
.org $629B
map_control_0c629b:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
