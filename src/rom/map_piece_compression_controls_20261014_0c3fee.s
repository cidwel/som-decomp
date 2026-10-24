.setcpu "65816"
.segment "CODE"
.org $3FEE
map_control_0c3fee:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
