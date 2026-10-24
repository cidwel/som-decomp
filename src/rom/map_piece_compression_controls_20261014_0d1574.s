.setcpu "65816"
.segment "CODE"
.org $1574
map_control_0d1574:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $94 ; row-distance/count
