.setcpu "65816"
.segment "CODE"
.org $7425
map_control_0e7425:
    .byte $E0 ; previous-row copy escape
    .byte $9D ; row-distance/count
    .byte $E1 ; previous-row copy count
