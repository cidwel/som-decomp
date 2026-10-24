.setcpu "65816"
.segment "CODE"
.org $8D81
map_control_0d8d81:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
