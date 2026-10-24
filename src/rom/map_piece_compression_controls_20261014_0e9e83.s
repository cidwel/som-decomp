.setcpu "65816"
.segment "CODE"
.org $9E83
map_control_0e9e83:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
