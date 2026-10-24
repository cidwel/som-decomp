.setcpu "65816"
.segment "CODE"
.org $1D6D
map_control_0d1d6d:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
