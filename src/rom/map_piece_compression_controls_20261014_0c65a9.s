.setcpu "65816"
.segment "CODE"
.org $65A9
map_control_0c65a9:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
