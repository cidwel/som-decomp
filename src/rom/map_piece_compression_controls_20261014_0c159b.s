.setcpu "65816"
.segment "CODE"
.org $159B
map_control_0c159b:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
