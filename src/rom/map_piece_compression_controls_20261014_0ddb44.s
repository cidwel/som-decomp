.setcpu "65816"
.segment "CODE"
.org $DB44
map_control_0ddb44:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
