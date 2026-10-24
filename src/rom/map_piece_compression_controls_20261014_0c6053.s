.setcpu "65816"
.segment "CODE"
.org $6053
map_control_0c6053:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
