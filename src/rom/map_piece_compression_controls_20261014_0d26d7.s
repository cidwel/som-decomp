.setcpu "65816"
.segment "CODE"
.org $26D7
map_control_0d26d7:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
