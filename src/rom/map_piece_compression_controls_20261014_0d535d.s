.setcpu "65816"
.segment "CODE"
.org $535D
map_control_0d535d:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
