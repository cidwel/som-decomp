.setcpu "65816"
.segment "CODE"
.org $1099
map_control_0c1099:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
