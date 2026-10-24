.setcpu "65816"
.segment "CODE"
.org $1442
map_control_0c1442:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
