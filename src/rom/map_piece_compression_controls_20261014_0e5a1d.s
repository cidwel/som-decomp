.setcpu "65816"
.segment "CODE"
.org $5A1D
map_control_0e5a1d:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
