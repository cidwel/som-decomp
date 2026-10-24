.setcpu "65816"
.segment "CODE"
.org $5F49
map_control_0c5f49:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
