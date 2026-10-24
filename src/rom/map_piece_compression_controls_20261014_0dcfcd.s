.setcpu "65816"
.segment "CODE"
.org $CFCD
map_control_0dcfcd:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
