.setcpu "65816"
.segment "CODE"
.org $F670
map_control_0ef670:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
