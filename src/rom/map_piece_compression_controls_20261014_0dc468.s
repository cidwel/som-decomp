.setcpu "65816"
.segment "CODE"
.org $C468
map_control_0dc468:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
