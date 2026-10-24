.setcpu "65816"
.segment "CODE"
.org $9C71
map_control_0e9c71:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
