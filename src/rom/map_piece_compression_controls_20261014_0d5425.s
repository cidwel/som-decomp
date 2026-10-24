.setcpu "65816"
.segment "CODE"
.org $5425
map_control_0d5425:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
