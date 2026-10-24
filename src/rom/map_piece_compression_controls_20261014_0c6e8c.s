.setcpu "65816"
.segment "CODE"
.org $6E8C
map_control_0c6e8c:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
