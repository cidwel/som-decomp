.setcpu "65816"
.segment "CODE"
.org $8964
map_control_0e8964:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
