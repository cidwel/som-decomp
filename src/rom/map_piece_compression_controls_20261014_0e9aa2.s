.setcpu "65816"
.segment "CODE"
.org $9AA2
map_control_0e9aa2:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $B6 ; row-distance/count
