.setcpu "65816"
.segment "CODE"
.org $8585
map_control_0e8585:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
