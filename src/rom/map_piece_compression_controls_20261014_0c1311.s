.setcpu "65816"
.segment "CODE"
.org $1311
map_control_0c1311:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
