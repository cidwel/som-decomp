.setcpu "65816"
.segment "CODE"
.org $30CD
map_control_0c30cd:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
