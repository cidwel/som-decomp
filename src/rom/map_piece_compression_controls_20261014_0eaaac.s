.setcpu "65816"
.segment "CODE"
.org $AAAC
map_control_0eaaac:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
