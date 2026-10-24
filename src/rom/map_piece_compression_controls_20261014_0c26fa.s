.setcpu "65816"
.segment "CODE"
.org $26FA
map_control_0c26fa:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
