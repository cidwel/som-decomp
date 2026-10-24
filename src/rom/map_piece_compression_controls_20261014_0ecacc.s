.setcpu "65816"
.segment "CODE"
.org $CACC
map_control_0ecacc:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
