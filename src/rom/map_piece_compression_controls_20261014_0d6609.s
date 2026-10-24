.setcpu "65816"
.segment "CODE"
.org $6609
map_control_0d6609:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
