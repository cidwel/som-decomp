.setcpu "65816"
.segment "CODE"
.org $56C7
map_control_0e56c7:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
