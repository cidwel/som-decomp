.setcpu "65816"
.segment "CODE"
.org $2E1D
map_control_0d2e1d:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
