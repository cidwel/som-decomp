.setcpu "65816"
.segment "CODE"
.org $2DD3
map_control_0c2dd3:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
