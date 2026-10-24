.setcpu "65816"
.segment "CODE"
.org $D1D8
map_control_0fd1d8:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E5 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
