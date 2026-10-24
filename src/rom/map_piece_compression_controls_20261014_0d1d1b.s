.setcpu "65816"
.segment "CODE"
.org $1D1B
map_control_0d1d1b:
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
