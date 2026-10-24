.setcpu "65816"
.segment "CODE"
.org $1D69
map_control_0e1d69:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E4 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
