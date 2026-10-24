.setcpu "65816"
.segment "CODE"
.org $B44F
map_control_0fb44f:
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
