.setcpu "65816"
.segment "CODE"
.org $0B66
map_control_0d0b66:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E2 ; previous-row copy count
