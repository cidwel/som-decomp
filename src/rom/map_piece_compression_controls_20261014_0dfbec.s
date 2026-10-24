.setcpu "65816"
.segment "CODE"
.org $FBEC
map_control_0dfbec:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
