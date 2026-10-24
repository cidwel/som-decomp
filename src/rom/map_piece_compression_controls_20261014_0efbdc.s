.setcpu "65816"
.segment "CODE"
.org $FBDC
map_control_0efbdc:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
