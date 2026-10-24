.setcpu "65816"
.segment "CODE"
.org $1957
map_control_0f1957:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
