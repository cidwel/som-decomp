.setcpu "65816"
.segment "CODE"
.org $9E77
map_control_0e9e77:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
