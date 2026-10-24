.setcpu "65816"
.segment "CODE"
.org $AAED
map_control_0eaaed:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
