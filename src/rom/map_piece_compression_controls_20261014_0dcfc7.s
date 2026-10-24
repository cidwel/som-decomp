.setcpu "65816"
.segment "CODE"
.org $CFC7
map_control_0dcfc7:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
