.setcpu "65816"
.segment "CODE"
.org $DFAF
map_control_0ddfaf:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
