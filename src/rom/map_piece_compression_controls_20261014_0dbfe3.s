.setcpu "65816"
.segment "CODE"
.org $BFE3
map_control_0dbfe3:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
