.setcpu "65816"
.segment "CODE"
.org $751F
map_control_0d751f:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
