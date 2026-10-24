.setcpu "65816"
.segment "CODE"
.org $9471
map_control_0f9471:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
