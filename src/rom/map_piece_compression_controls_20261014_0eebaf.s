.setcpu "65816"
.segment "CODE"
.org $EBAF
map_control_0eebaf:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
