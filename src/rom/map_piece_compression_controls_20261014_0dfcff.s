.setcpu "65816"
.segment "CODE"
.org $FCFF
map_control_0dfcff:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
