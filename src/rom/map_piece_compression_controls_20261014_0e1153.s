.setcpu "65816"
.segment "CODE"
.org $1153
map_control_0e1153:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
