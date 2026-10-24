.setcpu "65816"
.segment "CODE"
.org $F471
map_control_0ef471:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
