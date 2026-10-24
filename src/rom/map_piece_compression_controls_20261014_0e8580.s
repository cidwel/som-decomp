.setcpu "65816"
.segment "CODE"
.org $8580
map_control_0e8580:
    .byte $E0 ; previous-row copy escape
    .byte $97 ; row-distance/count
