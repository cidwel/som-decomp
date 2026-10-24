.setcpu "65816"
.segment "CODE"
.org $BEDF
map_control_0dbedf:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
