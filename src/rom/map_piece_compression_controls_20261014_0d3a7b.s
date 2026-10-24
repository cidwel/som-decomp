.setcpu "65816"
.segment "CODE"
.org $3A7B
map_control_0d3a7b:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
