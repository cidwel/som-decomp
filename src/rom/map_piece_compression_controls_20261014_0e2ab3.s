.setcpu "65816"
.segment "CODE"
.org $2AB3
map_control_0e2ab3:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
