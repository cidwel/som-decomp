.setcpu "65816"
.segment "CODE"
.org $5C29
map_control_0e5c29:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
