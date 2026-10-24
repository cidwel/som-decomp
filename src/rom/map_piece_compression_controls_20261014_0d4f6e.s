.setcpu "65816"
.segment "CODE"
.org $4F6E
map_control_0d4f6e:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
