.setcpu "65816"
.segment "CODE"
.org $1532
map_control_0c1532:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
