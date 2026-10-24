.setcpu "65816"
.segment "CODE"
.org $F687
map_control_0ef687:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
