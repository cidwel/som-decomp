.setcpu "65816"
.segment "CODE"
.org $1616
map_control_0f1616:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
