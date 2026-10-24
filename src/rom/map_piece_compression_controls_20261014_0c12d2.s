.setcpu "65816"
.segment "CODE"
.org $12D2
map_control_0c12d2:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
