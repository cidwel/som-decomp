.setcpu "65816"
.segment "CODE"
.org $3B74
map_control_0d3b74:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
