.setcpu "65816"
.segment "CODE"
.org $FCCD
map_control_0dfccd:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
