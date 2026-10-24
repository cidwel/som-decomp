.setcpu "65816"
.segment "CODE"
.org $8308
map_control_0e8308:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
