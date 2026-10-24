.setcpu "65816"
.segment "CODE"
.org $9E7D
map_control_0e9e7d:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
