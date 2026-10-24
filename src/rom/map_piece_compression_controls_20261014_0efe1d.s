.setcpu "65816"
.segment "CODE"
.org $FE1D
map_control_0efe1d:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
