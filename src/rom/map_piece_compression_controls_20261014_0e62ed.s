.setcpu "65816"
.segment "CODE"
.org $62ED
map_control_0e62ed:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
