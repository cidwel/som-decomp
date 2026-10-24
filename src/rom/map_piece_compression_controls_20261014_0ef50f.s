.setcpu "65816"
.segment "CODE"
.org $F50F
map_control_0ef50f:
    .byte $E0 ; previous-row copy escape
    .byte $B1 ; row-distance/count
    .byte $E2 ; previous-row copy count
