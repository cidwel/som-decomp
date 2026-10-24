.setcpu "65816"
.segment "CODE"
.org $8C8A
map_control_0c8c8a:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
