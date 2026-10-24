.setcpu "65816"
.segment "CODE"
.org $30E3
map_control_0c30e3:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
