.setcpu "65816"
.segment "CODE"
.org $AAAF
map_control_0faaaf:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
