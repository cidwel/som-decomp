.setcpu "65816"
.segment "CODE"
.org $20B9
map_control_0e20b9:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
