.setcpu "65816"
.segment "CODE"
.org $3F1C
map_control_0d3f1c:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
