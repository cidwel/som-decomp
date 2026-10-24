.setcpu "65816"
.segment "CODE"
.org $50CD
map_control_0e50cd:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
