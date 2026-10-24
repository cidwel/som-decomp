.setcpu "65816"
.segment "CODE"
.org $0909
map_control_0e0909:
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1D ; distance low bit/count
