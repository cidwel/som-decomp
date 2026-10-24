.setcpu "65816"
.segment "CODE"
.org $3B29
map_control_0c3b29:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
