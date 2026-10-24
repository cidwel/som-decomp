.setcpu "65816"
.segment "CODE"
.org $5334
map_control_0d5334:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
