.setcpu "65816"
.segment "CODE"
.org $1E8E
map_control_0f1e8e:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $08 ; distance low bit/count
