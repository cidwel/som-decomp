.setcpu "65816"
.segment "CODE"
.org $BDD4
map_control_0dbdd4:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
