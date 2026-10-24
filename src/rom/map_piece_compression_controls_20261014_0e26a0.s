.setcpu "65816"
.segment "CODE"
.org $26A0
map_control_0e26a0:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
