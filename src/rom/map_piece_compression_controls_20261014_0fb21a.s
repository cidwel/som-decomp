.setcpu "65816"
.segment "CODE"
.org $B21A
map_control_0fb21a:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
