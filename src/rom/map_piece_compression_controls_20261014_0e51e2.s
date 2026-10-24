.setcpu "65816"
.segment "CODE"
.org $51E2
map_control_0e51e2:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
    .byte $E1 ; previous-row copy count
