.setcpu "65816"
.segment "CODE"
.org $3ADE
map_control_0d3ade:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
