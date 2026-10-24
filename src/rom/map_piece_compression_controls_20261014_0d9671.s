.setcpu "65816"
.segment "CODE"
.org $9671
map_control_0d9671:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
