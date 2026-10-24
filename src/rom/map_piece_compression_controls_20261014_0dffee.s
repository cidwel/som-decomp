.setcpu "65816"
.segment "CODE"
.org $FFEE
map_control_0dffee:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
