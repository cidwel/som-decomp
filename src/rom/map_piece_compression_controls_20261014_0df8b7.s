.setcpu "65816"
.segment "CODE"
.org $F8B7
map_control_0df8b7:
    .byte $F5 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2D ; distance low bit/count
