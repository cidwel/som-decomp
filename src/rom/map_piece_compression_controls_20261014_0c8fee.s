.setcpu "65816"
.segment "CODE"
.org $8FEE
map_control_0c8fee:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
