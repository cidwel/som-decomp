.setcpu "65816"
.segment "CODE"
.org $D1FA
map_control_0fd1fa:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
