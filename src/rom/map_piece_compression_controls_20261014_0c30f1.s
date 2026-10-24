.setcpu "65816"
.segment "CODE"
.org $30F1
map_control_0c30f1:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
