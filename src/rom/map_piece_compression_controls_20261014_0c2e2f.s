.setcpu "65816"
.segment "CODE"
.org $2E2F
map_control_0c2e2f:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
