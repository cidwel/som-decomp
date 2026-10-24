.setcpu "65816"
.segment "CODE"
.org $3A8A
map_control_0d3a8a:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
