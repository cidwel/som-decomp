.setcpu "65816"
.segment "CODE"
.org $AAFF
map_control_0eaaff:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
