.setcpu "65816"
.segment "CODE"
.org $8549
map_control_0d8549:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
