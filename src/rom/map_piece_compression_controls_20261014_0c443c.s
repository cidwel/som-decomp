.setcpu "65816"
.segment "CODE"
.org $443C
map_control_0c443c:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
