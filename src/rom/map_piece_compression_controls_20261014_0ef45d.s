.setcpu "65816"
.segment "CODE"
.org $F45D
map_control_0ef45d:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
