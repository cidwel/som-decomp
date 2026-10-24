.setcpu "65816"
.segment "CODE"
.org $36ED
map_control_0e36ed:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
