.setcpu "65816"
.segment "CODE"
.org $2903
map_control_0d2903:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
