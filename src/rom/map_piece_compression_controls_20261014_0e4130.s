.setcpu "65816"
.segment "CODE"
.org $4130
map_control_0e4130:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
