.setcpu "65816"
.segment "CODE"
.org $ADAF
map_control_0fadaf:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
