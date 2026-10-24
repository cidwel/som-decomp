.setcpu "65816"
.segment "CODE"
.org $5F2A
map_control_0c5f2a:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
