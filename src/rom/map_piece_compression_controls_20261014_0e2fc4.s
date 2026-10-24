.setcpu "65816"
.segment "CODE"
.org $2FC4
map_control_0e2fc4:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
