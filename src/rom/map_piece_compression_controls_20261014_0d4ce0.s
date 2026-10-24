.setcpu "65816"
.segment "CODE"
.org $4CE0
map_control_0d4ce0:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
