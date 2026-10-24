.setcpu "65816"
.segment "CODE"
.org $C073
map_control_0ec073:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
