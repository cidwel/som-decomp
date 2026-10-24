.setcpu "65816"
.segment "CODE"
.org $EDB7
map_control_0dedb7:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $E2 ; previous-row copy count
