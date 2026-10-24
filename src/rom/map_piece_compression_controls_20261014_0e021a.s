.setcpu "65816"
.segment "CODE"
.org $021A
map_control_0e021a:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
