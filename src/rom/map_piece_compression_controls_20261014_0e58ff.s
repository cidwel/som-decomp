.setcpu "65816"
.segment "CODE"
.org $58FF
map_control_0e58ff:
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
