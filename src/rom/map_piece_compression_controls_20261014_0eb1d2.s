.setcpu "65816"
.segment "CODE"
.org $B1D2
map_control_0eb1d2:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E1 ; previous-row copy count
