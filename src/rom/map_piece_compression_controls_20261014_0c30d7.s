.setcpu "65816"
.segment "CODE"
.org $30D7
map_control_0c30d7:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
