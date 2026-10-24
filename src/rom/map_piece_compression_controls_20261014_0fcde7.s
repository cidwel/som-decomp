.setcpu "65816"
.segment "CODE"
.org $CDE7
map_control_0fcde7:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
