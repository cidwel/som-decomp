.setcpu "65816"
.segment "CODE"
.org $CDF7
map_control_0dcdf7:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E1 ; previous-row copy count
