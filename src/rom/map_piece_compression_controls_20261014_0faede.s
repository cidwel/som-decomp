.setcpu "65816"
.segment "CODE"
.org $AEDE
map_control_0faede:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
