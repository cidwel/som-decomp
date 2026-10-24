.setcpu "65816"
.segment "CODE"
.org $54BC
map_control_0e54bc:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
