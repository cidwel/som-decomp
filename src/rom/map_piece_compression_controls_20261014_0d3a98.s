.setcpu "65816"
.segment "CODE"
.org $3A98
map_control_0d3a98:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
