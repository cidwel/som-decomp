.setcpu "65816"
.segment "CODE"
.org $ABAF
map_control_0fabaf:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
