.setcpu "65816"
.segment "CODE"
.org $7928
map_control_0e7928:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
