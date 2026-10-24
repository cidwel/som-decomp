.setcpu "65816"
.segment "CODE"
.org $DBAF
map_control_0ddbaf:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
