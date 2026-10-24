.setcpu "65816"
.segment "CODE"
.org $5782
map_control_0e5782:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
