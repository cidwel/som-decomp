.setcpu "65816"
.segment "CODE"
.org $1347
map_control_0e1347:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
