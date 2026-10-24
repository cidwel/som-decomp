.setcpu "65816"
.segment "CODE"
.org $7687
map_control_0d7687:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
