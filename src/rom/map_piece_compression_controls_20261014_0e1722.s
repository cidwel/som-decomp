.setcpu "65816"
.segment "CODE"
.org $1722
map_control_0e1722:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E6 ; previous-row copy count
