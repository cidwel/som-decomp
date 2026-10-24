.setcpu "65816"
.segment "CODE"
.org $F204
map_control_0ef204:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
