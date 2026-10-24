.setcpu "65816"
.segment "CODE"
.org $CBAF
map_control_0ecbaf:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
