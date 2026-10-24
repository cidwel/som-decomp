.setcpu "65816"
.segment "CODE"
.org $5F0C
map_control_0c5f0c:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
