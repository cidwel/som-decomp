.setcpu "65816"
.segment "CODE"
.org $11DC
map_control_0c11dc:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
