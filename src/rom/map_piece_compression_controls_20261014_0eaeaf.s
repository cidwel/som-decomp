.setcpu "65816"
.segment "CODE"
.org $AEAF
map_control_0eaeaf:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
