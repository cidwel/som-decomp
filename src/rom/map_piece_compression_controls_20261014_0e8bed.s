.setcpu "65816"
.segment "CODE"
.org $8BED
map_control_0e8bed:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
