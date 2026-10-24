.setcpu "65816"
.segment "CODE"
.org $F48C
map_control_0ef48c:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
