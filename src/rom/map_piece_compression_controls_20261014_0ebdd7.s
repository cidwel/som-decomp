.setcpu "65816"
.segment "CODE"
.org $BDD7
map_control_0ebdd7:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
