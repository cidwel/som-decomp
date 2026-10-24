.setcpu "65816"
.segment "CODE"
.org $9C12
map_control_0e9c12:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $BF ; row-distance/count
