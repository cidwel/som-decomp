.setcpu "65816"
.segment "CODE"
.org $CDDF
map_control_0ecddf:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
