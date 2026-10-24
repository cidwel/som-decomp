.setcpu "65816"
.segment "CODE"
.org $1D93
map_control_0e1d93:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
