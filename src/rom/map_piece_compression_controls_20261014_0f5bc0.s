.setcpu "65816"
.segment "CODE"
.org $5BC0
map_control_0f5bc0:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
