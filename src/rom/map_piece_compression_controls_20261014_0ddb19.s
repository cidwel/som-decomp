.setcpu "65816"
.segment "CODE"
.org $DB19
map_control_0ddb19:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
