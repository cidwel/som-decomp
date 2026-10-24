.setcpu "65816"
.segment "CODE"
.org $178F
map_control_0e178f:
    .byte $E5 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E6 ; previous-row copy count
