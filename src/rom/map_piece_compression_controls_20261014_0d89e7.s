.setcpu "65816"
.segment "CODE"
.org $89E7
map_control_0d89e7:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
