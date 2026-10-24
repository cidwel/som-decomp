.setcpu "65816"
.segment "CODE"
.org $1352
map_control_0c1352:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
