.setcpu "65816"
.segment "CODE"
.org $F419
map_control_0ef419:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
