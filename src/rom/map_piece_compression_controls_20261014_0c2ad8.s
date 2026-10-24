.setcpu "65816"
.segment "CODE"
.org $2AD8
map_control_0c2ad8:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
