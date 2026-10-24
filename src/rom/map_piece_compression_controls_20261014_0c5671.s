.setcpu "65816"
.segment "CODE"
.org $5671
map_control_0c5671:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
