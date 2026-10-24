.setcpu "65816"
.segment "CODE"
.org $4B84
map_control_0e4b84:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
