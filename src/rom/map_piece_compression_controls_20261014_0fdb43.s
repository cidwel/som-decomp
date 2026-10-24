.setcpu "65816"
.segment "CODE"
.org $DB43
map_control_0fdb43:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
