.setcpu "65816"
.segment "CODE"
.org $1D7E
map_control_0e1d7e:
    .byte $E7 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
