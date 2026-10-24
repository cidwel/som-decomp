.setcpu "65816"
.segment "CODE"
.org $5A84
map_control_0d5a84:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
