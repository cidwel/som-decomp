.setcpu "65816"
.segment "CODE"
.org $8C4F
map_control_0c8c4f:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
