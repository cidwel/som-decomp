.setcpu "65816"
.segment "CODE"
.org $394F
map_control_0c394f:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
