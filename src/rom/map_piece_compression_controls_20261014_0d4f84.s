.setcpu "65816"
.segment "CODE"
.org $4F84
map_control_0d4f84:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
