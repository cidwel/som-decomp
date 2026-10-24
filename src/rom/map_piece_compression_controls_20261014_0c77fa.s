.setcpu "65816"
.segment "CODE"
.org $77FA
map_control_0c77fa:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
